#include <memory>
#include <string>
#include <sstream>

#include "Common.h"
#include "test_runner.h"


using namespace std;

string Print(const Expression* e)
{
    if (!e)
    {
        return "Null expression provided";
    }
    stringstream output;
    output << e->ToString() << " = " << e->Evaluate();
    return output.str();
}

//-----------------------------------------------------------------------------------//
class Multipl : public Expression
{
    public:
        explicit Multipl(ExpressionPtr _l, ExpressionPtr _r)
            : left(std::move(_l))
            , right(std::move(_r))
        {
        }

        std::string ToString() const
        {
            return "(" + left->ToString() + ")" + "*" + "(" + right->ToString() + ")";
        }

        int Evaluate() const
        {
            return left->Evaluate() * right->Evaluate();
        }

    private:
        ExpressionPtr left, right;
};

class Summ : public Expression
{
    public:
        explicit Summ(ExpressionPtr _l, ExpressionPtr _r)
            : left(std::move(_l))
            , right(std::move(_r))
        {
        }

        std::string ToString() const
        {
            return "(" + left->ToString() + ")" + "+" + "(" + right->ToString() + ")";
        }

        int Evaluate() const
        {
            return left->Evaluate() + right->Evaluate();
        }

    private:
        ExpressionPtr left, right;
};

class Number : public Expression
{
    public:
        explicit Number(const int val)
            : value(val)
        {
        }

        std::string ToString() const
        {
            return std::to_string(value);
        }

        int Evaluate() const
        {
            return value;
        }

    private:
        int value;
};
//-----------------------------------------------------------------------------------//

//-----------------------------------------------------------------------------------//
ExpressionPtr Value(int value)
{
    return std::make_unique<Number>(value);
}

ExpressionPtr Sum(ExpressionPtr left, ExpressionPtr right)
{
    return std::make_unique<Summ>(std::move(left), std::move(right));
}

ExpressionPtr Product(ExpressionPtr left, ExpressionPtr right)
{
    return std::make_unique<Multipl>(std::move(left), std::move(right));
}
//-----------------------------------------------------------------------------------//

void TestNumber()
{
    Number n(10);
    ASSERT_EQUAL(n.Evaluate(), 10);
    ASSERT_EQUAL(n.ToString(), "10");
}

void TestSumm()
{
    Number first(10);
    Number second(15);

    Summ s(make_unique<Number>(first), make_unique<Number>(second));

    ASSERT_EQUAL(s.Evaluate(), 25);
    ASSERT_EQUAL(s.ToString(), "(10)+(15)");
}

void TestMult()
{
    Number first(10);
    Number second(15);

    Multipl m(make_unique<Number>(first), make_unique<Number>(second));

    ASSERT_EQUAL(m.Evaluate(), 150);
    ASSERT_EQUAL(m.ToString(), "(10)*(15)");
}

void Test()
{
    ExpressionPtr e1 = Product(Value(2), Sum(Value(3), Value(4)));
    ASSERT_EQUAL(Print(e1.get()), "(2)*((3)+(4)) = 14");

    ExpressionPtr e2 = Sum(move(e1), Value(5));
    ASSERT_EQUAL(Print(e2.get()), "((2)*((3)+(4)))+(5) = 19");

    ASSERT_EQUAL(Print(e1.get()), "Null expression provided");
}

int main()
{
    TestRunner tr;

    RUN_TEST(tr, TestNumber);
    RUN_TEST(tr, TestSumm);
    RUN_TEST(tr, TestMult);
    RUN_TEST(tr, Test);

    return 0;
}
