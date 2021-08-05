#include "tests.h"

void TestClassDate() {
    {
        {
            ostringstream testing;
            Date date(2020, 12, 31);
            string expected = "2020-12-31";
            testing << date;
            AssertEqual(testing.str(), expected, "Date constructor #1");
        }
        {
            ostringstream testing;
            Date date = ParseDate("2020-12-31");
            string expected = "2020-12-31";
            testing << date;
            AssertEqual(testing.str(), expected, "ParseDate function");
        }
    }
    {
        {
            int year = 2020, month = 13, day = 31;
            try {
                Date date(year, month, day);
            } catch (exception& ex) {
                string testing = ex.what();
                string expected = "Month value is invalid: " + to_string(month);
                AssertEqual(testing, expected, "Date constructor Month Exception");
            }
        }
        {
            int year = 2020, month = 12, day = 32;
            try {
                Date date(year, month, day);
            } catch (exception& ex) {
                string testing = ex.what();
                string expected = "Day value is invalid: " + to_string(day);
                AssertEqual(testing, expected, "Date constructor Day Exception");
            }
        }
        {
            int year = 0, month = 13, day = 32;
            try {
                Date date(year, month, day);
            } catch (exception& ex) {
                string testing = ex.what();
                string expected = "Month value is invalid: " + to_string(month);
                AssertEqual(testing, expected, "Date constructor Day Exception");
            }
        }
    }
    {
        {
            string date = "2020---02-10";
            try {
                ParseDate(date);
            } catch (exception& ex) {
                string testing = ex.what();
                string expected = "Wrong date format: " + date;
                AssertEqual(testing, expected, "Date constructor Day Exception");
            }
        }
        {
            string date = "2020--02-10";
            try {
                ParseDate(date);
            } catch (exception& ex) {
                string testing = ex.what();
                string expected = "Month value is invalid: -2";
                AssertEqual(testing, expected, "Date constructor Day Exception");
            }
        }
        {
            string date = "2020-02--10";
            try {
                ParseDate(date);
            } catch (exception& ex) {
                string testing = ex.what();
                string expected = "Day value is invalid: -10";
                AssertEqual(testing, expected, "Date constructor Day Exception");
            }
        }
        {
            string date = "--2020-02-10";
            try {
                ParseDate(date);
            } catch (exception& ex) {
                string testing = ex.what();
                string expected = "Wrong date format: --2020-02-10";
                AssertEqual(testing, expected, "Date constructor Day Exception");
            }
        }
    }
    {
        {
            Date date1 = ParseDate("2020-10-15");
            Date date2 = ParseDate("2020-10-16");
            bool expression = date1 < date2;
            AssertEqual(expression, true, "Date testing comparision #1");
        }
        {
            Date date1 = ParseDate("2019-12-31");
            Date date2 = ParseDate("2020-10-16");
            bool expression = date1 < date2;
            AssertEqual(expression, true, "Date testing comparision #2");
        }
        {
            Date date1 = ParseDate("2021-11-01");
            Date date2 = ParseDate("2021-12-01");
            bool expression = date1 < date2;
            AssertEqual(expression, true, "Date testing comparision #2");
        }
    }
}

/*void TestParseCondition() {
    {
        istringstream is("date != 2017-11-18");
        shared_ptr<Node> root = ParseCondition(is);
        Assert(root->Evaluate({2017, 1, 1}, ""), "Parse condition 1");
        Assert(!root->Evaluate({2017, 11, 18}, ""), "Parse condition 2");
    }
    {
        istringstream is(R"(event == "sport event")");
        shared_ptr<Node> root = ParseCondition(is);
        Assert(root->Evaluate({2017, 1, 1}, "sport event"), "Parse condition 3");
        Assert(!root->Evaluate({2017, 1, 1}, "holiday"), "Parse condition 4");
    }
    {
        istringstream is("date >= 2017-01-01 AND date < 2017-07-01");
        shared_ptr<Node> root = ParseCondition(is);
        Assert(root->Evaluate({2017, 1, 1}, ""), "Parse condition 5");
        Assert(root->Evaluate({2017, 3, 1}, ""), "Parse condition 6");
        Assert(root->Evaluate({2017, 6, 30}, ""), "Parse condition 7");
        Assert(!root->Evaluate({2017, 7, 1}, ""), "Parse condition 8");
        Assert(!root->Evaluate({2016, 12, 31}, ""), "Parse condition 9");
    }
    {
        istringstream is(R"(event != "sport event" AND event != "Wednesday")");
        shared_ptr<Node> root = ParseCondition(is);
        Assert(root->Evaluate({2017, 1, 1}, "holiday"), "Parse condition 10");
        Assert(!root->Evaluate({2017, 1, 1}, "sport event"), "Parse condition 11");
        Assert(!root->Evaluate({2017, 1, 1}, "Wednesday"), "Parse condition 12");
    }
    {
        istringstream is(R"(event == "holiday AND date == 2017-11-18")");
        shared_ptr<Node> root = ParseCondition(is);
        Assert(!root->Evaluate({2017, 11, 18}, "holiday"), "Parse condition 13");
        Assert(!root->Evaluate({2017, 11, 18}, "work day"), "Parse condition 14");
        Assert(root->Evaluate({1, 1, 1}, "holiday AND date == 2017-11-18"), "Parse condition 15");
    }
    {
        istringstream is(R"(((event == "holiday" AND date == 2017-01-01)))");
        shared_ptr<Node> root = ParseCondition(is);
        Assert(root->Evaluate({2017, 1, 1}, "holiday"), "Parse condition 16");
        Assert(!root->Evaluate({2017, 1, 2}, "holiday"), "Parse condition 17");
    }
    {
        istringstream is(R"(date > 2017-01-01 AND (event == "holiday" OR date < 2017-07-01))");
        shared_ptr<Node> root = ParseCondition(is);
        Assert(!root->Evaluate({2016, 1, 1}, "holiday"), "Parse condition 18");
        Assert(root->Evaluate({2017, 1, 2}, "holiday"), "Parse condition 19");
        Assert(root->Evaluate({2017, 1, 2}, "workday"), "Parse condition 20");
        Assert(!root->Evaluate({2018, 1, 2}, "workday"), "Parse condition 21");
    }
    {
        istringstream is(R"(date > 2017-01-01 AND event == "holiday" OR date < 2017-07-01)");
        shared_ptr<Node> root = ParseCondition(is);
        Assert(root->Evaluate({2016, 1, 1}, "event"), "Parse condition 22");
        Assert(root->Evaluate({2017, 1, 2}, "holiday"), "Parse condition 23");
        Assert(root->Evaluate({2017, 1, 2}, "workday"), "Parse condition 24");
        Assert(!root->Evaluate({2018, 1, 2}, "workday"), "Parse condition 25");
    }
    {
        istringstream is(R"(((date == 2017-01-01 AND event == "holiday")))");
        shared_ptr<Node> root = ParseCondition(is);
        Assert(root->Evaluate({2017, 1, 1}, "holiday"), "Parse condition 26");
        Assert(!root->Evaluate({2017, 1, 2}, "holiday"), "Parse condition 27");
    }
    {
        istringstream is(R"(((event == "2017-01-01" OR date > 2016-01-01)))");
        shared_ptr<Node> root = ParseCondition(is);
        Assert(root->Evaluate({1, 1, 1}, "2017-01-01"), "Parse condition 28");
        Assert(!root->Evaluate({2016, 1, 1}, "event"), "Parse condition 29");
        Assert(root->Evaluate({2016, 1, 2}, "event"), "Parse condition 30");
    }
}

void TestParseEvent() {
    {
        istringstream is("event");
        AssertEqual(ParseEvent(is), "event", "Parse event without leading spaces");
    }
    {
        istringstream is("     sport event ");
        AssertEqual(ParseEvent(is), "sport event ", "Parse event with leading spaces");
    }
    {
        istringstream is("    first event   \n   second event");
        vector<string> events;
        events.push_back(ParseEvent(is));
        events.push_back(ParseEvent(is));
        AssertEqual(events, vector<string>{"first event   ", "second event"}, "Parse multiple events");
    }
}*/


void TestAll() {
    cerr << "------------------Tests-----------------------" << endl;
    TestRunner tr;
    tr.RunTest(TestClassDate, "TestClassDate");

/*    tr.RunTest(TestParseEvent, "TestParseEvent");

    tr.RunTest(TestParseCondition, "TestParseCondition");*/

    cerr << "----------------------------------------------" << endl << endl;
}
