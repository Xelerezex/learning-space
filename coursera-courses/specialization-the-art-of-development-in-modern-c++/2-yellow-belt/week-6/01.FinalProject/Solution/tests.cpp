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

void TestParseCondition() {
    unsigned test_counter = 0;


    { // BASIC OPERATION WITH EVALUATE FOR [DATE]: [!=, ==, >, <, >=, <=]. NO : [AND, OR, (, )]
        {
            istringstream is("date < 2020-10-20");
            shared_ptr<Node> root = ParseCondition(is);
            Assert(root->Evaluate({2020, 10, 19}, ""), ("Parse condition " + to_string(++test_counter)));   // 1
            Assert(!root->Evaluate({2020, 10, 20}, ""), ("Parse condition " + to_string(++test_counter)));  // 2
            Assert(!root->Evaluate({2020, 10, 21}, ""), ("Parse condition " + to_string(++test_counter)));  // 3
        }
        {
            istringstream is("date <= 2020-10-20");
            shared_ptr<Node> root = ParseCondition(is);
            Assert(root->Evaluate({2020, 10, 19}, ""), ("Parse condition " + to_string(++test_counter)));   // 4
            Assert(root->Evaluate({2020, 10, 20}, ""), ("Parse condition " + to_string(++test_counter)));   // 5
            Assert(!root->Evaluate({2020, 10, 21}, ""), ("Parse condition " + to_string(++test_counter)));  // 6
        }
        {
            istringstream is("date > 2020-10-20");
            shared_ptr<Node> root = ParseCondition(is);
            Assert(!root->Evaluate({2020, 10, 19}, ""), ("Parse condition " + to_string(++test_counter)));  // 7
            Assert(!root->Evaluate({2020, 10, 20}, ""), ("Parse condition " + to_string(++test_counter)));  // 8
            Assert(root->Evaluate({2020, 10, 21}, ""), ("Parse condition " + to_string(++test_counter)));   // 9
        }
        {
            istringstream is("date >= 2020-10-20");
            shared_ptr<Node> root = ParseCondition(is);
            Assert(!root->Evaluate({2020, 10, 19}, ""), ("Parse condition " + to_string(++test_counter)));  // 10
            Assert(root->Evaluate({2020, 10, 20}, ""), ("Parse condition " + to_string(++test_counter)));   // 11
            Assert(root->Evaluate({2020, 10, 21}, ""), ("Parse condition " + to_string(++test_counter)));   // 12
        }
        {
            istringstream is("date != 2017-11-18");
            shared_ptr<Node> root = ParseCondition(is);
            Assert(root->Evaluate({2017, 1, 1}, ""), ("Parse condition " + to_string(++test_counter)));     // 13 C
            Assert(!root->Evaluate({2017, 11, 18}, ""), ("Parse condition " + to_string(++test_counter)));  // 14 C
        }
        {
            istringstream is("date == 2020-10-10");
            shared_ptr<Node> root = ParseCondition(is);
            Assert(!root->Evaluate({2021, 10, 10}, ""), ("Parse condition " + to_string(++test_counter)));  // 15
            Assert(root->Evaluate({2020, 10, 10}, ""), ("Parse condition " + to_string(++test_counter)));   // 16
        }
    }
    { // BASIC OPERATION WITH EVALUATE FOR [EVENT]: [!=, ==]. NO : [AND, OR, (, )]
        {
            istringstream is(R"(event == "sport event")");
            shared_ptr<Node> root = ParseCondition(is);
            Assert(root->Evaluate({2017, 1, 1}, "sport event"), ("Parse condition " + to_string(++test_counter))); // 17 C
            Assert(!root->Evaluate({2017, 1, 1}, "holiday"), ("Parse condition " + to_string(++test_counter)));    // 17 C
        }
        {
            istringstream is(R"(event != "Some Sport Stuff")");
            shared_ptr<Node> root = ParseCondition(is);
            Assert(!root->Evaluate({2021, 10, 10}, "Some Sport Stuff"), ("Parse condition " + to_string(++test_counter)));  // 18
            Assert(root->Evaluate({2020, 10, 10}, "New Year"), ("Parse condition " + to_string(++test_counter)));           // 19
        }
    }
    { // LOGICAL OPERATIONS : [OR, AND]; NO : [(, )]
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
}


void TestClassDBAddPrint() {
    {
        {
            string e1 = "First Event", e2 = "Second Event", e3 = "Third Event";

            string line = "2020-12-30";
            istringstream ist(line);
            Date d1 = ParseDate(ist);

            vector<string> dq1({e1, e2, e3});


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

            vector<string> dq1({e1, e2, e3});
            vector<string> dq2({e4, e5});
            vector<string> dq3({e5, e1});


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
    { // Tests for PRINT from gist: https://gist.github.com/SergeiShumilin/a030350c6226b8091b57ed0c7ccba779
        {
            Database db;
            db.Add({2017, 1, 1}, "new year");
            db.Add({2017, 1, 7}, "xmas");
            ostringstream out;
            db.Print(out);
            AssertEqual("2017-01-01 new year\n2017-01-07 xmas\n", out.str(), "straight ordering");
        }
        {
            Database db;
            db.Add({2017, 1, 1}, "new year");
            db.Add({2017, 1, 1}, "holiday");
            ostringstream out;
            db.Print(out);
            AssertEqual("2017-01-01 new year\n2017-01-01 holiday\n", out.str(), "several in one day");
        }
        {
            Database db;
            db.Add({2017, 1, 7}, "xmas");
            db.Add({2017, 1, 1}, "new year");
            ostringstream out;
            db.Print(out);
            AssertEqual("2017-01-01 new year\n2017-01-07 xmas\n", out.str(), "reverse ordering");
        }
        {
            Database db;
            db.Add({2017, 1, 1}, "new year");
            db.Add({2017, 1, 1}, "new year");
            db.Add({2017, 1, 1}, "xmas");
            db.Add({2017, 1, 1}, "new year");
            ostringstream out;
            db.Print(out);
            AssertEqual("2017-01-01 new year\n2017-01-01 xmas\n", out.str(), "uniq adding");
        }
    }
}



int DoRemove (Database& db, const string& str) {
        istringstream is (str);
        auto condition = ParseCondition(is);
        auto predicate = [condition](const Date &date, const string &event) {
            return condition->Evaluate(date, event);
        };
        return db.RemoveIf(predicate);
}
void TestClassDBDel() {
    {   // Tests for DEL from gist: https://gist.github.com/SergeiShumilin/a030350c6226b8091b57ed0c7ccba779
        Database db;
        db.Add({2017, 1, 1}, "new year");
        db.Add({2017, 1, 7}, "xmas");

        ostringstream out;

        AssertEqual(0, DoRemove(db, R"(event == "something")"), "Remove nothing");
        AssertEqual(1, DoRemove(db, R"(date == "2017-01-01")"), "Remove by date");

        db.Print(out);
        AssertEqual("2017-01-07 xmas\n", out.str(), "Remove by date, left");
    }
    {
        Database db;
        ostringstream out;

        db.Add({2017, 6, 1}, "1st of June");
        db.Add({2017, 7, 8}, "8th of July");
        db.Add({2017, 7, 8}, "Someone's birthday");

        AssertEqual(2, DoRemove(db, R"(date == "2017-07-08")"), "Remove by date, 2 entries");

        db.Print(out);
        AssertEqual("2017-06-01 1st of June\n", out.str(), "Remove by date, 2 entries");
    }
    {
        Database db;
        ostringstream out;

        db.Add({1, 1, 1}, "Jesus Birth");               // Does not Del
        db.Add({1, 1, 1}, "holiday");                   // Del
        db.Add({2016, 12, 30}, "Some stupid shit");     // Does not Del
        db.Add({2016, 12, 30}, "holiday");              // Del
        db.Add({2016, 12, 30}, "sport event");          // Del
        db.Add({2016, 12, 31}, "New Year");             // Does not Del
        db.Add({2017, 1, 1}, "Live plz");               // Does not Del

        db.Add({2020, 8, 7}, "holiday");                // Does not Del
        db.Add({2020, 8, 7}, "sport event");            // Does not Del
        db.Add({2020, 8, 7}, "Someone's birthday");     // Does not Del

        AssertEqual(3, DoRemove(db, R"(date < 2017-01-01 AND (event == "holiday" OR event == "sport event"))"), "Remove by date, 3 entries");

        db.Print(out);
        AssertEqual("0001-01-01 Jesus Birth\n2016-12-30 Some stupid shit\n2016-12-31 New Year\n2017-01-01 Live plz\n2020-08-07 holiday\n2020-08-07 sport event\n2020-08-07 Someone's birthday\n", out.str(), "Remove by date, 3 entries. Print");
    }
        {
        Database db;
        ostringstream out;

        db.Add({1, 1, 1}, "Jesus Birth");               // Del
        db.Add({1, 1, 1}, "holiday");                   // Del
        db.Add({2016, 12, 30}, "Some stupid shit");     // Del
        db.Add({2016, 12, 30}, "holiday");              // Del
        db.Add({2016, 12, 30}, "sport event");          // Del
        db.Add({2016, 12, 31}, "New Year");             // Del
        db.Add({2017, 1, 1}, "Live plz");               // Del

        db.Add({2020, 8, 7}, "holiday");                // Del
        db.Add({2020, 8, 7}, "sport event");            // Del
        db.Add({2020, 8, 7}, "Someone's birthday");     // Del

        AssertEqual(10, DoRemove(db, R"()"), "Remove All, 10 entries");

        db.Print(out);
        AssertEqual("", out.str(), "Remove by date, 10 entries. Print");
    }
}

string DoFind (Database& db, const string& str) {
    istringstream is (str);
    auto condition = ParseCondition(is);
    auto predicate = [condition](const Date &date, const string &event) {
        return condition->Evaluate(date, event);
    };
    const auto entries = db.FindIf(predicate);
    ostringstream os;
    for (const auto& entry : entries) {
        os << entry << endl;
    }
    os << entries.size();
    return os.str();
}

void TestClassDBFind() {
    {   // Tests for FIND from gist: https://gist.github.com/SergeiShumilin/a030350c6226b8091b57ed0c7ccba779
        {
            Database db;
            db.Add({2017, 1, 1}, "new year");
            db.Add({2017, 1, 7}, "xmas");
            AssertEqual("2017-01-01 new year\n1", DoFind(db, "date == 2017-01-01"), "simple find by date");
            AssertEqual("2017-01-01 new year\n2017-01-07 xmas\n2", DoFind(db, "date < 2017-01-31"), "multiple find by date");
            AssertEqual("2017-01-01 new year\n1", DoFind(db, R"(event != "xmas")"), "multiple find by holiday");
        }
        {
            Database db;
            db.Add({2017, 1, 1}, "new year");
            db.Add({2017, 1, 1}, "new year2");
            db.Add({2017, 1, 7}, "xmas");
            AssertEqual("2017-01-01 new year\n2017-01-07 xmas\n2", DoFind(db, R"(date == 2017-01-07 OR event == "new year")"),
                    "complex find or");
            AssertEqual("2017-01-01 new year\n1", DoFind(db, R"(date == 2017-01-01 AND event == "new year")"),
                        "complex find and");
            AssertEqual("0", DoFind(db, R"(date == 2017-01-09 AND event == "new year")"),
                        "complex find and, nothing");
        }
    }
}

void TestAll() {
    cerr << "------------------Tests-----------------------" << endl;
    TestRunner tr;

    tr.RunTest(TestClassDate, "Test_Class_Date");
    tr.RunTest(TestParseEvent, "Test_Parse_Event");
    tr.RunTest(TestParseCondition, "Test_Parse_Condition");
    tr.RunTest(TestClassDBAddPrint, "Test_Class_Datebase_ADD_PRINT");
    tr.RunTest(TestClassDBDel, "Test_Class_Datebase_Del");
    tr.RunTest(TestClassDBFind, "Test_Class_Datebase_Find");

    cerr << "----------------------------------------------" << endl << endl;
}
