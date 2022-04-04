#include "test_runner.h"
#include <functional>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;


struct Email
{
    string from;
    string to;
    string body;
};


class Worker
{
    public:
        virtual ~Worker() = default;
        virtual void Process(unique_ptr<Email> email) = 0;
        virtual void Run()
        {
            // только первому worker-у в пайплайне нужно это имплементировать
            throw logic_error("Unimplemented");
        }

    protected:
        // реализации должны вызывать PassOn, чтобы передать объект дальше
        // по цепочке обработчиков
        void PassOn(unique_ptr<Email> email) const
        {
            if(next)
            {
                next->Process(move(email));
            }
        }

    public:
        void SetNext(unique_ptr<Worker> next_) {
            next = move(next_);
        }

    private:
        unique_ptr<Worker> next;
};


class Reader : public Worker
{
    public:
        explicit Reader(istream& in)
            : in(in)
        {
        }

        void Process(unique_ptr<Email>) override
        {
        }

        void Run() override
        {
            for(;;)
            {
                auto email = make_unique<Email>();
                getline(in, email->from);
                getline(in, email->to);
                getline(in, email->body);
                if (in)
                {
                    PassOn(move(email));
                }
                else
                {
                    break;
                }
            }
        }

    private:
        istream& in;
};


class Filter : public Worker
{
    public:
        using Function = function<bool(const Email&)>;

    public:
        explicit Filter(Function func_)
            : func(move(func_))
        {

        }

        void Process(unique_ptr<Email> email) override
        {
            if (func(*email))
            {
                PassOn(move(email));
            }
        }

    private:
        Function func;
};


class Copier : public Worker
{
    public:
        explicit Copier(string to_)
            : to(move(to_))
        {}

        void Process(unique_ptr<Email> email) override
        {
            if(email->to != to)
            {
                auto copy = make_unique<Email>(*email);
                copy->to = to;
                PassOn(move(email));
                PassOn(move(copy));
            }
            else
            {
                PassOn(move(email));
            }
        }

    private:
        string to;
};


class Sender : public Worker
{
    public:
        explicit Sender(ostream& out_)
            : out(out_)
        {
        }

        void Process(unique_ptr<Email> email) override
        {
            out << email->from << endl
                << email->to << endl
                << email->body << endl;
            PassOn(move(email));
        }

    private:
        ostream& out;
};


// реализуйте класс
class PipelineBuilder
{
    public:
        // добавляет в качестве первого обработчика Reader
        explicit PipelineBuilder(istream& in)
        {
            workers.push_back(make_unique<Reader>(in));
        }

        // добавляет новый обработчик Filter
        PipelineBuilder& FilterBy(Filter::Function filter)
        {
            workers.push_back(make_unique<Filter>(move(filter)));
            return *this;
        }

        // добавляет новый обработчик Copier
        PipelineBuilder& CopyTo(string recipient)
        {
            workers.push_back(make_unique<Copier>(move(recipient)));
            return *this;
        }

        // добавляет новый обработчик Sender
        PipelineBuilder& Send(ostream& out)
        {
            workers.push_back(make_unique<Sender>(out));
            return *this;
        }

        // возвращает готовую цепочку обработчиков
        unique_ptr<Worker> Build()
        {
            for (size_t i = workers.size() - 1; i > 0; --i)
            {
                workers[i - 1]->SetNext(move(workers[i]));
            }
            return move(workers[0]);
    }

    private:
        vector<unique_ptr<Worker>> workers;
};


void TestSanity()
{
    string input = (
        "erich@example.com\n"
        "richard@example.com\n"
        "Hello there\n"

        "erich@example.com\n"
        "ralph@example.com\n"
        "Are you sure you pressed the right button?\n"

        "ralph@example.com\n"
        "erich@example.com\n"
        "I do not make mistakes of that kind\n"
    );
    istringstream inStream(input);
    ostringstream outStream;

    PipelineBuilder builder(inStream);
    builder.FilterBy(
        [](const Email& email) {
            return email.from == "erich@example.com";
    });
    builder.CopyTo("richard@example.com");
    builder.Send(outStream);
    auto pipeline = builder.Build();

    pipeline->Run();

    string expectedOutput = (
        "erich@example.com\n"
        "richard@example.com\n"
        "Hello there\n"

        "erich@example.com\n"
        "ralph@example.com\n"
        "Are you sure you pressed the right button?\n"

        "erich@example.com\n"
        "richard@example.com\n"
        "Are you sure you pressed the right button?\n"
    );

    ASSERT_EQUAL(expectedOutput, outStream.str());
}

int main()
{
    TestRunner tr;
    RUN_TEST(tr, TestSanity);
    return 0;
}
