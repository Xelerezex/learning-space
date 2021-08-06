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

            string line = "2020-12-31";
            istringstream ist(line);
            Date date = ParseDate(ist);

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
            istringstream ist(date);
            try {

                ParseDate(ist);
            } catch (exception& ex) {
                string testing = ex.what();
                string expected = "Wrong date format."; // + date mb some day
                AssertEqual(testing, expected, "Date constructor Day Exception");
            }
        }
        {
            string date = "2020--02-10";
            istringstream ist(date);
            try {
                ParseDate(ist);
            } catch (exception& ex) {
                string testing = ex.what();
                string expected = "Month value is invalid: -2";
                AssertEqual(testing, expected, "Date constructor Day Exception");
            }
        }
        {
            string date = "2020-02--10";
            istringstream ist(date);
            try {
                ParseDate(ist);
            } catch (exception& ex) {
                string testing = ex.what();
                string expected = "Day value is invalid: -10";
                AssertEqual(testing, expected, "Date constructor Day Exception");
            }
        }
        {
            string date = "--2020-02-10";
            istringstream ist(date);
            try {
                ParseDate(ist);
            } catch (exception& ex) {
                string testing = ex.what();
                string expected = "Wrong date format."; // + date mb some day
                AssertEqual(testing, expected, "Date constructor Day Exception");
            }
        }
    }
    {
        {   string line1 = "2020-10-15";
            istringstream ist1(line1);
            Date date1 = ParseDate(ist1);

            string line2 = "2020-10-16";
            istringstream ist2(line2);
            Date date2 = ParseDate(ist2);

            bool expression = date1 < date2;
            AssertEqual(expression, true, "Date testing comparision #1");
        }
        {
            string line1 = "2019-12-31";
            istringstream ist1(line1);
            Date date1 = ParseDate(ist1);

            string line2 = "2020-10-16";
            istringstream ist2(line2);
            Date date2 = ParseDate(ist2);

            bool expression = date1 < date2;
            AssertEqual(expression, true, "Date testing comparision #2");
        }
        {
            string line1 = "2021-11-01";
            istringstream ist1(line1);
            Date date1 = ParseDate(ist1);

            string line2 = "2021-12-01";
            istringstream ist2(line2);
            Date date2 = ParseDate(ist2);

            bool expression = date1 < date2;
            AssertEqual(expression, true, "Date testing comparision #2");
        }
    }
}

void TestParseEvent() {
    { // My tests:
        {
            string expected = "Someone's birthday FUCK!";
            istringstream is(expected);
            const auto testing = ParseEvent(is);
            AssertEqual(testing, expected, "ParseEvent for Datebase testing #1");
        }
        {
            string expected = "! @ # $ \% \% ^ & * ( ) \\ ";
            istringstream is(expected);
            const auto testing = ParseEvent(is);
            AssertEqual(testing, expected, "ParseEvent for Datebase testing #2");
        }
    }
    { // Course tests:
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
    }
}

void TestClassDatebase() {
    {
        {
            string e1 = "Test event";

            string line = "2020-12-30";
            istringstream ist(line);
            Date d1 = ParseDate(ist);

            deque<string> dq1({e1});


            DBType expected = {
                {d1, dq1}, // "2020-12-30" : {"Test event"}
            };

            Database testing;
            testing.Add(d1, e1);

            AssertEqual(testing.GetAllData(), expected, "ADD for Datebase testing #1");
        }
        {
            string e1 = "First Event", e2 = "Second Event", e3 = "Third Event";

            string line = "2020-12-30";
            istringstream ist(line);
            Date d1 = ParseDate(ist);

            deque<string> dq1({e3, e2, e1});


            DBType expected = {
                {d1, dq1},          // "2020-12-30" : {"First Event", "Second Event", "Third Event"}
            };

            Database testing;       // Should Added only one event from each doubling
            testing.Add(d1, e1);
            testing.Add(d1, e1);
            testing.Add(d1, e2);
            testing.Add(d1, e2);
            testing.Add(d1, e3);
            testing.Add(d1, e3);

            AssertEqual(testing.GetAllData(), expected, "ADD for Datebase testing #2");
        }
        {
            string e1 = "First 1234 Event", e2 = "Second # Event", e3 = "Third @ Event", e4 = "Fourth ~ Event", e5 = "Fifth ! Event";


            string line1 = "2020-12-30";
            istringstream ist1(line1);
            Date d1 = ParseDate(ist1);

            string line2 = "2019-12-30";
            istringstream ist2(line2);
            Date d2 = ParseDate(ist2);

            string line3 = "2020-12-30";
            istringstream ist3(line3);
            Date d3 = ParseDate(ist3);

            string line4 = "0000-01-01";
            istringstream ist4(line4);
            Date d5 = ParseDate(ist4);

            deque<string> dq1({e3, e2, e1});
            deque<string> dq2({e5, e4});
            deque<string> dq3({e1, e5});


            DBType expected = {
                {d1, dq1},          // "2020-12-30" : {"First 1234 Event", "Second # Event", "Third @ Event"}
                {d2, dq2},          // "2019-12-30" : {"Fourth ~ Event", "Fifth ! Event"}
                {d5, dq3},          // "0000-01-01" : {"Fifth ! Event", "First 1234 Event"}

            };

            Database testing;       // Should Added only one event from each doubling
            testing.Add(d1, e1);
            testing.Add(d1, e2);
            testing.Add(d1, e2);
            testing.Add(d1, e3);
            testing.Add(d1, e3);

            testing.Add(d3, e1);    // Dubling but with another obj
            testing.Add(d3, e2);
            testing.Add(d3, e2);
            testing.Add(d3, e3);
            testing.Add(d3, e3);

            testing.Add(d2, e4);
            testing.Add(d2, e5);
            testing.Add(d2, e5);

            testing.Add(d5, e5);
            testing.Add(d5, e5);
            testing.Add(d5, e1);

            AssertEqual(testing.GetAllData(), expected, "ADD for Datebase testing #3");
        }
    }
}

/*
void TestParseCondition() {
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
*/


void TestAll() {
    cerr << "------------------Tests-----------------------" << endl;
    TestRunner tr;

    tr.RunTest(TestClassDate, "TestClassDate");
    tr.RunTest(TestParseEvent, "TestParseEvent");
    tr.RunTest(TestClassDatebase, "TestClassDatebase");

/*    tr.RunTest(TestParseCondition, "TestParseCondition");*/

    cerr << "----------------------------------------------" << endl << endl;
}
