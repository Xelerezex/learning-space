// Файл stats_aggregator.h

#pragma once

#include <ostream>
#include <limits>
#include <memory>
#include <vector>
#include <optional>
#include <unordered_map>

struct StatsAggregator
{
    virtual ~StatsAggregator()
    {
    }

    virtual void Process(int value) = 0;
    virtual void PrintValue(std::ostream& out) const = 0;
};

namespace StatsAggregators
{

class Sum : public StatsAggregator
{
public:
    void Process(int value) override;
    void PrintValue(std::ostream& out) const override;

private:
    int sum = 0;
};

class Min : public StatsAggregator
{
public:
    void Process(int value) override;
    void PrintValue(std::ostream& out) const override;

private:
    std::optional<int> current_min;
};

class Max : public StatsAggregator
{
public:
    void Process(int value) override;
    void PrintValue(std::ostream& out) const override;

private:
    std::optional<int> current_max;
};

class Average : public StatsAggregator
{
public:
    void Process(int value) override;
    void PrintValue(std::ostream& out) const override;

private:
    int sum = 0;
    int total = 0;
};

class Mode : public StatsAggregator
{
public:
    void Process(int value) override;
    void PrintValue(std::ostream& out) const override;

private:
    std::unordered_map<int, int> count;
    std::optional<int> mode;
};

class Composite : public StatsAggregator
{
public:
    void Process(int value) override;
    void PrintValue(std::ostream& output) const override;

    void Add(std::unique_ptr<StatsAggregator> aggr);

private:
    std::vector<std::unique_ptr<StatsAggregator>> aggregators;
};

void TestSum();
void TestMin();
void TestMax();
void TestAverage();
void TestMode();
void TestComposite();

}

// Файл stats_aggregator.cpp

#include "stats_aggregator.h"

using namespace std;

namespace StatsAggregators
{

template <typename T>
ostream& operator << (ostream& os, const optional<T>& v)
{
    if (v)
    {
        os << *v;
    } else
    {
        os << "undefined";
    }
    return os;
}

void Composite::Process(int value)
{
    for (auto& aggr : aggregators)
    {
        aggr->Process(value);
    }
}

void Composite::PrintValue(std::ostream& output) const
{
    for (const auto& aggr : aggregators)
    {
        aggr->PrintValue(output);
        output << '\n';
    }
}

void Composite::Add(std::unique_ptr<StatsAggregator> aggr)
{
    aggregators.push_back(std::move(aggr));
}

void Sum::Process(int value)
{
    sum += value;
}

void Sum::PrintValue(std::ostream& out) const
{
    out << "Sum is " << sum;
}

void Min::Process(int value)
{
    if (!current_min || value < *current_min)
    {
        current_min = value;
    }
}

void Min::PrintValue(std::ostream& out) const
{
    out << "Min is " << current_min;
}

void Max::Process(int value)
{
    if (!current_max || value > *current_max)
    {
        current_max = value;
    }
}

void Max::PrintValue(std::ostream& out) const
{
    out << "Max is " << current_max;
}

void Average::Process(int value)
{
    sum += value;
    ++total;
}

void Average::PrintValue(std::ostream& out) const
{
    out << "Average is ";
    if (total == 0)
    {
        out << "undefined";
    } else
    {
        out << sum / total;
    }
}

void Mode::Process(int value)
{
    int current_count = ++count[value];
    if (!mode || current_count > count[*mode])
    {
        mode = value;
    }
}

void Mode::PrintValue(std::ostream& out) const
{
    out << "Mode is " << mode;
}

}

// Файл stats_aggregator_test.cpp

#include "stats_aggregator.h"
#include "test_runner.h"

#include <sstream>
using namespace std;

namespace StatsAggregators
{

string PrintedValue(const StatsAggregator& aggr)
{
    ostringstream output;
    aggr.PrintValue(output);
    return output.str();
}

void TestSum()
{
    Sum aggr;
    ASSERT_EQUAL(PrintedValue(aggr), "Sum is 0");

    aggr.Process(3);
    aggr.Process(8);
    aggr.Process(-1);
    aggr.Process(16);

    ASSERT_EQUAL(PrintedValue(aggr), "Sum is 26");
}

void TestMin()
{
    Min aggr;
    ASSERT_EQUAL(PrintedValue(aggr), "Min is undefined");

    aggr.Process(3);
    aggr.Process(8);
    aggr.Process(-1);
    aggr.Process(16);

    ASSERT_EQUAL(PrintedValue(aggr), "Min is -1");
}

void TestMax()
{
    Max aggr;
    ASSERT_EQUAL(PrintedValue(aggr), "Max is undefined");

    aggr.Process(3);
    aggr.Process(8);
    aggr.Process(-1);
    aggr.Process(16);

    ASSERT_EQUAL(PrintedValue(aggr), "Max is 16");
}

void TestAverage()
{
    Average aggr;
    ASSERT_EQUAL(PrintedValue(aggr), "Average is undefined");

    aggr.Process(3);
    aggr.Process(8);
    aggr.Process(-1);
    aggr.Process(16);

    ASSERT_EQUAL(PrintedValue(aggr), "Average is 6");
}

void TestMode()
{
    Mode aggr;
    ASSERT_EQUAL(PrintedValue(aggr), "Mode is undefined");

    aggr.Process(3);
    aggr.Process(3);
    aggr.Process(8);
    aggr.Process(8);
    aggr.Process(8);
    aggr.Process(8);
    aggr.Process(-1);
    aggr.Process(-1);
    aggr.Process(-1);
    aggr.Process(16);

    ASSERT_EQUAL(PrintedValue(aggr), "Mode is 8");
}

void TestComposite()
{
    Composite aggr;
    aggr.Add(make_unique<Sum>());
    aggr.Add(make_unique<Min>());
    aggr.Add(make_unique<Max>());
    aggr.Add(make_unique<Average>());
    aggr.Add(make_unique<Mode>());

    aggr.Process(3);
    aggr.Process(8);
    aggr.Process(-1);
    aggr.Process(16);
    aggr.Process(16);

    string expected = "Sum is 42\n";
    expected += "Min is -1\n";
    expected += "Max is 16\n";
    expected += "Average is 8\n";
    expected += "Mode is 16\n";
    ASSERT_EQUAL(PrintedValue(aggr), expected);
}

}


// Файл main.cpp

#include "test_runner.h"
#include "stats_aggregator.h"

#include <vector>
#include <string>
#include <map>
#include <memory>
#include <iostream>
#include <unordered_map>
#include <functional>
using namespace std;

void TestAll();

unique_ptr<StatsAggregator> ReadAggregators(istream& input)
{
    using namespace StatsAggregators;

    const unordered_map<string, std::function<unique_ptr<StatsAggregator>()>> known_builders =
    {

       {"sum", []
       { return make_unique<Sum>(); }},

       {"min", []
       { return make_unique<Min>(); }},

       {"max", []
       { return make_unique<Max>(); }},

       {"avg", []
       { return make_unique<Average>(); }},

       {"mode", []
       { return make_unique<Mode>(); }}
    };

    auto result = make_unique<Composite>();

    int aggr_count;
    input >> aggr_count;

    string line;
    for (int i = 0; i < aggr_count; ++i)
    {
        input >> line;
        result->Add(known_builders.at(line)());
    }

    return result;
}

int main()
{
    TestAll();

    auto stats_aggregator = ReadAggregators(cin);

    for (int value; cin >> value; )
    {
        stats_aggregator->Process(value);
    }
    stats_aggregator->PrintValue(cout);

    return 0;
}

void TestAll()
{
    TestRunner tr;

    RUN_TEST(tr, StatsAggregators::TestSum);
    RUN_TEST(tr, StatsAggregators::TestMin);
    RUN_TEST(tr, StatsAggregators::TestMax);
    RUN_TEST(tr, StatsAggregators::TestAverage);
    RUN_TEST(tr, StatsAggregators::TestMode);
    RUN_TEST(tr, StatsAggregators::TestComposite);
}

