#include "tests.h"


// Testing Class Date
void TestClassDate() {

    // Testing creatring of object:

    {
        {   // Testing Date constructor
            ostringstream testing;
            Date date(2020, 12, 31);
            const string expected = "2020-12-31";
            testing << date;
            AssertEqual(testing.str(), expected, "Date constructor #1");        // 1
        }
        {   // Testing ParseDate copy to constructor
            ostringstream testing;
            const string expected = "2020-12-31";
            istringstream ist(expected);
            Date date = ParseDate(ist);
            testing << date;
            AssertEqual(testing.str(), expected, "Date constructor #2 (With ParseDate)");       // 2
        }
    }

    // Testing Class Date exceptions, if realization of parsing like from white belt:

    {
        {   // Testing MONTH value exception:
            const int year = 2020, month = 13, day = 31;
            try {
                Date date(year, month, day);
            } catch (exception& ex) {
                const string testing = ex.what();
                const string expected = "Month value is invalid: " + to_string(month);
                AssertEqual(testing, expected, "Date constructor Exception #1: MONTH");     // 3
            }
        }
        {   // Testing DAY value exception:
            const int year = 2020, month = 12, day = 32;
            try {
                Date date(year, month, day);
            } catch (exception& ex) {
                const string testing = ex.what();
                const string expected = "Day value is invalid: " + to_string(day);
                AssertEqual(testing, expected, "Date constructor Exception #2: DAY");       // 4
            }
        }
        {   // Testing MONTH+DAY, where MONTH goes first, value exception:
            const int year = 0, month = 13, day = 32;
            try {
                Date date(year, month, day);
            } catch (exception& ex) {
                const string testing = ex.what();
                const string expected = "Month value is invalid: " + to_string(month);
                AssertEqual(testing, expected, "Date constructor Exception #3: MONTH+DAY");     // 5
            }
        }
        {   // Testing wrong format of input date exception:
            const string date = "2020---02-10";
            istringstream ist(date);
            try {
                ParseDate(ist);
            } catch (exception& ex) {
                const string testing = ex.what();
                const string expected = "Wrong date format.";
                AssertEqual(testing, expected, "Date constructor Exception #4: DATE FORMAT");       // 6
            }
        }
        {   // Testing wrong format of input date exception:
            const string date = "--2020-02-10";
            istringstream ist(date);
            try {
                ParseDate(ist);
            } catch (exception& ex) {
                const string testing = ex.what();
                const string expected = "Wrong date format.";
                AssertEqual(testing, expected, "Date constructor Exception #5: DATE FORMAT");       // 7
            }
        }
        {   // Testing wrong format of input date, which cause invalid MONTH value exception
            const string date = "2020--02-10";
            istringstream ist(date);
            try {
                ParseDate(ist);
            } catch (exception& ex) {
                const string testing = ex.what();
                const string expected = "Month value is invalid: -2";
                AssertEqual(testing, expected, "Date constructor Exception #6: DATE FORMAT -> MONTH VALUE");        // 8
            }
        }
        {   // Testing wrong format of input date, which cause invalid DAY value exception
            const string date = "2020-02--10";
            istringstream ist(date);
            try {
                ParseDate(ist);
            } catch (exception& ex) {
                const string testing = ex.what();
                const string expected = "Day value is invalid: -10";
                AssertEqual(testing, expected, "Date constructor Exception #7: DATE FORMAT -> MONTH VALUE");        // 9
            }
        }
    }

    // Testing Date object comparision:

    {   // Testing Date object comparision <
        {   istringstream ist1("2020-10-15");
            Date date1 = ParseDate(ist1);

            istringstream ist2("2020-10-16");
            Date date2 = ParseDate(ist2);

            AssertEqual((date1 < date2), true, "Date comparision #1: <");      // 10
        }
        {   // Testing Date object comparision <
            istringstream ist1("2019-12-31");
            Date date1 = ParseDate(ist1);

            istringstream ist2("2020-10-16");
            Date date2 = ParseDate(ist2);

            AssertEqual((date1 < date2), true, "Date comparision #2: <");      // 11
        }
        {   // Testing Date object comparision <
            istringstream ist1("2021-11-01");
            Date date1 = ParseDate(ist1);

            istringstream ist2("2021-12-01");
            Date date2 = ParseDate(ist2);

            AssertEqual((date1 < date2), true, "Date comparision #3: <");      // 12
        }
    }
}


// Testing Function ParseDate:
void TestParseEvent() {

    // Random tests:

    {
        {   // Testing with default string
            const string expected = "Someone's birthday FUCK!";
            istringstream is(expected);
            const auto testing = ParseEvent(is);
            AssertEqual(testing, expected, "ParseEvent function #1:");       // 13
        }
        {   //  Testing with symbols string
            const string expected = "! @ # $ \% \% ^ & * ( ) \\ ";
            istringstream is(expected);
            const auto testing = ParseEvent(is);
            AssertEqual(testing, expected, "ParseEvent function #2:");       // 14
        }
        {   //  Testing with space in the front
            string expected = "~~~```/*/*Z0(_incdw";
            istringstream is("                                  ~~~```/*/*Z0(_incdw");
            const auto testing = ParseEvent(is);
            AssertEqual(testing, expected, "ParseEvent function #2:");       // 15
        }
    }

    // Course's tests:

    {
        {   // Testing with default string
            istringstream is("event");
            AssertEqual(ParseEvent(is), "event", "Parse event without leading spaces");     //16
        }
        {   //  Testing with space in the front
            istringstream is("     sport event ");
            AssertEqual(ParseEvent(is), "sport event ", "Parse event with leading spaces");     // 17
        }
        {   //  Testing with space in the front
            istringstream is("    first event   \n   second event");
            vector<string> events;
            events.push_back(ParseEvent(is));
            events.push_back(ParseEvent(is));
            AssertEqual(events, vector<string>{"first event   ", "second event"}, "Parse multiple events");     // 18
        }
    }
}


// Testing Function ParseDate:
void TestParseCondition() {

    // BASIC OPERATION WITH EVALUATE FOR [DATE]: [!=, ==, >, <, >=, <=]. NO : [AND, OR, (, )]:

    {
        {   // Testing with date and <
            istringstream is("date < 2020-10-20");
            shared_ptr<Node> root = ParseCondition(is);
            Assert(root->Evaluate({2020, 10, 19}, ""), "Parse condition #1: date < 2020-10-20");   // 19
            Assert(!root->Evaluate({2020, 10, 20}, ""), "Parse condition #2: date < 2020-10-20");  // 20
            Assert(!root->Evaluate({2020, 10, 21}, ""), "Parse condition #3: date < 2020-10-20");  // 21
        }
        {   // Testing with date and <=
            istringstream is("date <= 2020-10-20");
            shared_ptr<Node> root = ParseCondition(is);
            Assert(root->Evaluate({2020, 10, 19}, ""), "Parse condition #1: date <= 2020-10-20");   // 22
            Assert(root->Evaluate({2020, 10, 20}, ""), "Parse condition #2: date <= 2020-10-20");   // 23
            Assert(!root->Evaluate({2020, 10, 21}, ""), "Parse condition #3: date <= 2020-10-20");  // 24
        }
        {   // Testing with date and >
            istringstream is("date > 2020-10-20");
            shared_ptr<Node> root = ParseCondition(is);
            Assert(!root->Evaluate({2020, 10, 19}, ""), "Parse condition #1: date > 2020-10-20");  // 25
            Assert(!root->Evaluate({2020, 10, 20}, ""), "Parse condition #2: date > 2020-10-20");  // 26
            Assert(root->Evaluate({2020, 10, 21}, ""), "Parse condition #3: date > 2020-10-20");   // 27
        }
        {   // Testing with date and >=
            istringstream is("date >= 2020-10-20");
            shared_ptr<Node> root = ParseCondition(is);
            Assert(!root->Evaluate({2020, 10, 19}, ""), "Parse condition #1: date >= 2020-10-20");  // 28
            Assert(root->Evaluate({2020, 10, 20}, ""), "Parse condition #1: date >= 2020-10-20");   // 29
            Assert(root->Evaluate({2020, 10, 21}, ""), "Parse condition #1: date >= 2020-10-20");   // 30
        }
        {   // Testing with date and !=
            istringstream is("date != 2017-11-18");
            shared_ptr<Node> root = ParseCondition(is);
            Assert(root->Evaluate({2017, 1, 1}, ""), "Parse condition #1: date != 2017-11-18");     // 31
            Assert(!root->Evaluate({2017, 11, 18}, ""), "Parse condition #2: date != 2017-11-18");  // 32
        }
        {   // Testing with date and ==
            istringstream is("date == 2020-10-10");
            shared_ptr<Node> root = ParseCondition(is);
            Assert(!root->Evaluate({2021, 10, 10}, ""), "Parse condition #1: date == 2020-10-10");  // 33
            Assert(root->Evaluate({2020, 10, 10}, ""), "Parse condition #2: date == 2020-10-10");   // 34
        }
    }

    // BASIC OPERATION WITH EVALUATE FOR [EVENT]: [!=, ==]. NO : [AND, OR, (, )]

    {
        {   // Testing with event and ==
            istringstream is(R"(event == "sport event")");
            shared_ptr<Node> root = ParseCondition(is);
            Assert(root->Evaluate({2017, 1, 1}, "sport event"), R"("Parse condition #1: event == "sport event")"); // 35
            Assert(!root->Evaluate({2017, 1, 1}, "holiday"), R"("Parse condition #2: event == "sport event")");    // 36
        }
        {   // Testing with event and !=
            istringstream is(R"(event != "Some Sport Stuff")");
            shared_ptr<Node> root = ParseCondition(is);
            Assert(!root->Evaluate({2021, 10, 10}, "Some Sport Stuff"), R"("Parse condition #1: event != "Some Sport Stuff")");  // 38
            Assert(root->Evaluate({2020, 10, 10}, "New Year"), R"("Parse condition #2: event != "Some Sport Stuff")");           // 39
        }
    }

    // LOGICAL OPERATIONS : [OR, AND]; NO : [(, )]

    {
        {   // Testing with date and >, <, AND
            istringstream is("date >= 2017-01-01 AND date < 2017-07-01");
            shared_ptr<Node> root = ParseCondition(is);
            Assert(root->Evaluate({2017, 1, 1}, ""), "Parse condition #1: date >= 2017-01-01 AND date < 2017-07-01");       // 40
            Assert(root->Evaluate({2017, 3, 1}, ""), "Parse condition #2: date >= 2017-01-01 AND date < 2017-07-01");       // 41
            Assert(root->Evaluate({2017, 6, 30}, ""), "Parse condition #3: date >= 2017-01-01 AND date < 2017-07-01");      // 42
            Assert(!root->Evaluate({2017, 7, 1}, ""), "Parse condition #4: date >= 2017-01-01 AND date < 2017-07-01");      // 43
            Assert(!root->Evaluate({2016, 12, 31}, ""), "Parse condition #5: date >= 2017-01-01 AND date < 2017-07-01");    // 44
        }
        {   // Testing with event and !=, AND
            istringstream is(R"(event != "sport event" AND event != "Wednesday")");
            shared_ptr<Node> root = ParseCondition(is);
            Assert(root->Evaluate({2017, 1, 1}, "holiday"), R"(Parse condition #1: event != "sport event" AND event != "Wednesday")");      // 45
            Assert(!root->Evaluate({2017, 1, 1}, "sport event"), R"(Parse condition #2: event != "sport event" AND event != "Wednesday")");     //46
            Assert(!root->Evaluate({2017, 1, 1}, "Wednesday"), R"(Parse condition #3: event != "sport event" AND event != "Wednesday")");       // 47
        }
        {   // Testing with date, event and ==, AND
            istringstream is(R"(event == "holiday AND date == 2017-11-18")");
            shared_ptr<Node> root = ParseCondition(is);
            Assert(!root->Evaluate({2017, 11, 18}, "holiday"), R"(Parse condition #1: event == "holiday AND date == 2017-11-18")");       // 48
            Assert(!root->Evaluate({2017, 11, 18}, "work day"), R"(Parse condition #2: event == "holiday AND date == 2017-11-18")");      // 49
            Assert(root->Evaluate({1, 1, 1}, "holiday AND date == 2017-11-18"), R"(Parse condition #1: event == "holiday AND date == 2017-11-18")");      //50
        }
    }

     // LOGICAL OPERATIONS AND PARENTHESIS: [OR, AND, (, )]

    {
        {   // Testing with event, date and ==, AND, (, )
            istringstream is(R"(((event == "holiday" AND date == 2017-01-01)))");
            shared_ptr<Node> root = ParseCondition(is);
            Assert(root->Evaluate({2017, 1, 1}, "holiday"), R"(Parse condition #1: ((event == "holiday" AND date == 2017-01-01)) )" );      // 51
            Assert(!root->Evaluate({2017, 1, 2}, "holiday"), R"(Parse condition #2: ((event == "holiday" AND date == 2017-01-01)) )" );     // 52
        }
        {   // Testing with event, date and >, <, ==, OR, AND
            istringstream is(R"(date > 2017-01-01 AND (event == "holiday" OR date < 2017-07-01))");
            shared_ptr<Node> root = ParseCondition(is);
            Assert(!root->Evaluate({2016, 1, 1}, "holiday"), R"(Parse condition #1: date > 2017-01-01 AND (event == "holiday" OR date < 2017-07-01))");     // 53
            Assert(root->Evaluate({2017, 1, 2}, "holiday"), R"(Parse condition #2: date > 2017-01-01 AND (event == "holiday" OR date < 2017-07-01))");      // 54
            Assert(root->Evaluate({2017, 1, 2}, "workday"), R"(Parse condition #3: date > 2017-01-01 AND (event == "holiday" OR date < 2017-07-01))");      // 55
            Assert(!root->Evaluate({2018, 1, 2}, "workday"), R"(Parse condition #4: date > 2017-01-01 AND (event == "holiday" OR date < 2017-07-01))");     // 56
        }
        {   // Testing with event, date and >, < == OR, AND
            istringstream is(R"(date > 2017-01-01 AND event == "holiday" OR date < 2017-07-01)");
            shared_ptr<Node> root = ParseCondition(is);
            Assert(root->Evaluate({2016, 1, 1}, "event"), R"(Parse condition #1: date > 2017-01-01 AND event == "holiday" OR date < 2017-07-01)");        // 57
            Assert(root->Evaluate({2017, 1, 2}, "holiday"), R"(Parse condition #2: date > 2017-01-01 AND event == "holiday" OR date < 2017-07-01)");      // 58
            Assert(root->Evaluate({2017, 1, 2}, "workday"), R"(Parse condition #3: date > 2017-01-01 AND event == "holiday" OR date < 2017-07-01)");      // 59
            Assert(!root->Evaluate({2018, 1, 2}, "workday"), R"(Parse condition #4: date > 2017-01-01 AND event == "holiday" OR date < 2017-07-01)");     // 60
        }
        {   // Testing with event, date == AND (, )
            istringstream is(R"(((date == 2017-01-01 AND event == "holiday")))");
            shared_ptr<Node> root = ParseCondition(is);
            Assert(root->Evaluate({2017, 1, 1}, "holiday"), R"(Parse condition #1: ((date == 2017-01-01 AND event == "holiday")))");      // 61
            Assert(!root->Evaluate({2017, 1, 2}, "holiday"), R"(Parse condition #2: ((date == 2017-01-01 AND event == "holiday")))");     // 62
        }
        {   // Testing with event, date and > == OR
            istringstream is(R"(((event == "2017-01-01" OR date > 2016-01-01)))");
            shared_ptr<Node> root = ParseCondition(is);
            Assert(root->Evaluate({1, 1, 1}, "2017-01-01"), R"(Parse condition #1: ((event == "2017-01-01" OR date > 2016-01-01)))");      // 63
            Assert(!root->Evaluate({2016, 1, 1}, "event"), R"(Parse condition #2: ((event == "2017-01-01" OR date > 2016-01-01)))");       // 64
            Assert(root->Evaluate({2016, 1, 2}, "event"), R"(Parse condition #3: ((event == "2017-01-01" OR date > 2016-01-01)))");        // 65
        }
    }
}


// Side Function for testing all Nodes:
class ReverseEmptyNode : public Node {
    // Reverse - because EmptyNode always true
    bool Evaluate(const Date&, const std::string& event) const override {
        return false;
    }
};


// Testing Class EmptyNode:
void TestEmptyNode() {
    {   // Testing Class EmptyNode, method Evaluate should always gives true
        EmptyNode en;
        Assert(en.Evaluate(Date{0, 1, 1}, "Boy"), "EmptyNode Class #1:");
        Assert(en.Evaluate(Date{2017, 11, 18}, "Boy Boy"), "EmptyNode Class #2:");
        Assert(en.Evaluate(Date{9999, 12, 31}, "Boy Boy Oh Boooy"), "EmptyNode Class #3:");
    }
}


// Testing Class DateComparisonNode:
void TestDateComparisonNode() {
    {   // Testing case: date == date
        DateComparisonNode dcn(Comparison::Equal, {2017, 11, 18});
        Assert(dcn.Evaluate(Date{2017, 11, 18}, ""), "DateComparisonNode Class #1:");
        Assert(!dcn.Evaluate(Date{2017, 11, 19}, ""), "DateComparisonNode Class #2:");
    }
    {   // Testing case: date != date
        DateComparisonNode dcn(Comparison::NotEqual, {2017, 11, 18});
        Assert(dcn.Evaluate(Date{2017, 11, 19}, ""), "DateComparisonNode Class #3:");
        Assert(!dcn.Evaluate(Date{2017, 11, 18}, ""), "DateComparisonNode Class #4:");
    }
    {   // Testing case: date < date
        DateComparisonNode dcn(Comparison::Less, {2017, 11, 18});
        Assert(dcn.Evaluate(Date{2017, 11, 17}, ""), "DateComparisonNode Class #5:");
        Assert(!dcn.Evaluate(Date{2017, 11, 18}, ""), "DateComparisonNode Class #6:");
        Assert(!dcn.Evaluate(Date{2017, 11, 19}, ""), "DateComparisonNode Class #7:");
    }
    {   // Testing case: date > date
        DateComparisonNode dcn(Comparison::Greater, {2017, 11, 18});
        Assert(dcn.Evaluate(Date{2017, 11, 19}, ""), "DateComparisonNode Class #8:");
        Assert(!dcn.Evaluate(Date{2017, 11, 18}, ""), "DateComparisonNode Class #9:");
        Assert(!dcn.Evaluate(Date{2017, 11, 17}, ""), "DateComparisonNode Class #10:");
    }
    {   // Testing case: date <= date
        DateComparisonNode dcn(Comparison::LessOrEqual, {2017, 11, 18});
        Assert(dcn.Evaluate(Date{2017, 11, 17}, ""), "DateComparisonNode Class #11:");
        Assert(dcn.Evaluate(Date{2017, 11, 18}, ""), "DateComparisonNode Class #12:");
        Assert(!dcn.Evaluate(Date{2017, 11, 19}, ""), "DateComparisonNode Class #13:");
    }
    {   // Testing case: date >= date
        DateComparisonNode dcn(Comparison::GreaterOrEqual, {2017, 11, 18});
        Assert(dcn.Evaluate(Date{2017, 11, 19}, ""), "DateComparisonNode Class #14:");
        Assert(dcn.Evaluate(Date{2017, 11, 18}, ""), "DateComparisonNode Class #15:");
        Assert(!dcn.Evaluate(Date{2017, 11, 17}, ""), "DateComparisonNode Class #16:");
    }
}


// Testing Class DateComparisonNode:
void TestEventComparisonNode() {
    {   // Testing case: AAAAA == AAAAA
        EventComparisonNode ecn(Comparison::Equal, "AAAAA");
        Assert(ecn.Evaluate(Date{0, 1, 1}, "AAAAA"), "EventComparison Class #1:");
        Assert(!ecn.Evaluate(Date{0, 1, 1}, "BBBBB"), "EventComparison Class #2:");
    }
    {   // Testing case: AAAAA != BBBBB
        EventComparisonNode ecn(Comparison::NotEqual, "AAAAA");
        Assert(ecn.Evaluate(Date{0, 1, 1}, "BBBBB"), "EventComparison Class #3:");
        Assert(!ecn.Evaluate(Date{0, 1, 1}, "AAAAA"), "EventComparison Class #4:");
    }
    {   // Testing case: BBBBB < AAAAA
        EventComparisonNode ecn(Comparison::Less, "BBBBB");
        Assert(ecn.Evaluate(Date{0, 1, 1}, "AAAAA"), "EventComparison Class #5:");
        Assert(!ecn.Evaluate(Date{0, 1, 1}, "BBBBB"), "EventComparison Class #6:");
        Assert(!ecn.Evaluate(Date{0, 1, 1}, "CCCCC"), "EventComparison Class #7:");
    }
    {   // Testing case: BBBBB > CCCCC
        EventComparisonNode ecn(Comparison::Greater, "BBBBB");
        Assert(ecn.Evaluate(Date{0, 1, 1}, "CCCCC"), "EventComparison Class #8:");
        Assert(!ecn.Evaluate(Date{0, 1, 1}, "BBBBB"), "EventComparison Class #9:");
        Assert(!ecn.Evaluate(Date{0, 1, 1}, "AAAAA"), "EventComparison Class #10:");
    }
    {   // Testing case: BBBBB <= AAAAA
        EventComparisonNode ecn(Comparison::LessOrEqual, "BBBBB");
        Assert(ecn.Evaluate(Date{0, 1, 1}, "AAAAA"), "EventComparison Class #11:");
        Assert(ecn.Evaluate(Date{0, 1, 1}, "BBBBB"), "EventComparison Class #12:");
        Assert(!ecn.Evaluate(Date{0, 1, 1}, "CCCCC"), "EventComparison Class #13:");
    }
    {   // Testing case: BBBBB >= CCCCC
        EventComparisonNode ecn(Comparison::GreaterOrEqual, "BBBBB");
        Assert(ecn.Evaluate(Date{0, 1, 1}, "CCCCC"), "EventComparison Class #14:");
        Assert(ecn.Evaluate(Date{0, 1, 1}, "BBBBB"), "EventComparison Class #15:");
        Assert(!ecn.Evaluate(Date{0, 1, 1}, "AAAAA"), "EventComparison Class #16:");
    }
}


// Testing Class TestLogicalOperationNode:
void TestLogicalOperationNode() {
    {   // true AND true = true
        LogicalOperationNode lon(LogicalOperation::And, make_shared<EmptyNode>(), make_shared<EmptyNode>());
        Assert(lon.Evaluate(Date{0, 1, 1}, "AAAAA"), "LogicalOperationNode Class #1:");
    }
    {   // false AND true = false
        LogicalOperationNode lon(LogicalOperation::And, make_shared<ReverseEmptyNode>(), make_shared<EmptyNode>());
        Assert(!lon.Evaluate(Date{0, 1, 1}, "AAAAA"), "LogicalOperationNode Class #2:");
    }
    {   // true AND false = false
        LogicalOperationNode lon(LogicalOperation::And, make_shared<EmptyNode>(), make_shared<ReverseEmptyNode>());
        Assert(!lon.Evaluate(Date{0, 1, 1}, "AAAAA"), "LogicalOperationNode Class #3:");
    }
    {   // false AND false = false
        LogicalOperationNode lon(LogicalOperation::And, make_shared<ReverseEmptyNode>(), make_shared<ReverseEmptyNode>());
        Assert(!lon.Evaluate(Date{0, 1, 1}, "AAAAA"), "LogicalOperationNode Class #4:");
    }
    {   // true OR true = true
        LogicalOperationNode lon(LogicalOperation::Or, make_shared<EmptyNode>(), make_shared<EmptyNode>());
        Assert(lon.Evaluate(Date{0, 1, 1}, "AAAAA"), "LogicalOperationNode Class #5:");
    }
    {   // false OR true = true
        LogicalOperationNode lon(LogicalOperation::Or, make_shared<ReverseEmptyNode>(), make_shared<EmptyNode>());
        Assert(lon.Evaluate(Date{0, 1, 1}, "AAAAA"), "LogicalOperationNode Class #6:");
    }
    {   // true OR false = true
        LogicalOperationNode lon(LogicalOperation::Or, make_shared<EmptyNode>(), make_shared<ReverseEmptyNode>());
        Assert(lon.Evaluate(Date{0, 1, 1}, "AAAAA"), "LogicalOperationNode Class #7:");
    }
    {   // false OR false = false
        LogicalOperationNode lon(LogicalOperation::Or, make_shared<ReverseEmptyNode>(), make_shared<ReverseEmptyNode>());
        Assert(!lon.Evaluate(Date{0, 1, 1}, "AAAAA"), "LogicalOperationNode Class #8:");
    }
}


// Side Function for testing hole Database:
DBType Database::GetAllData() const {
    return DataBaseStorage;
}


// Testing Class Datebase, Method Datebase::Add:
void TestClassDBAdd() {
    {   // Testing Add function to one date with repetitions
        const string event_1 = "First Event", event_2 = "Second Event", event_3 = "Third Event";

        DBType expected = {
            {{2020, 12, 30}, {event_1, event_2, event_3}},    // "2020-12-30" : {"First Event", "Second Event", "Third Event"}
        };

        Database testing;
        testing.Add({2020, 12, 30}, event_1);
        testing.Add({2020, 12, 30}, event_1);
        testing.Add({2020, 12, 30}, event_2);
        testing.Add({2020, 12, 30}, event_2);
        testing.Add({2020, 12, 30}, event_3);
        testing.Add({2020, 12, 30}, event_3);

        AssertEqual(testing.GetAllData(), expected, "Class Database Method Add #1:");
    }
    {   // Testing Add function to one date with repetitions to different dates, insertion order
        const string event_1 = "First 1234 Event", event_2 = "Second # Event",
                     event_3 = "Third @ Event", event_4 = "Fourth ~ Event",
                     event_5 = "Fifth ! Event";

        DBType expected = {
            {{0, 1, 1},      {event_4, event_5}},               // "0000-01-01" : {"Fifth ! Event", "First 1234 Event"}
            {{2019, 12, 30}, {event_1, event_3}},               // "2019-12-30" : {"Fourth ~ Event", "Fifth ! Event"}
            {{2020, 12, 30}, {event_1, event_2, event_3}},      // "2020-12-30" : {"First 1234 Event", "Second # Event", "Third @ Event"}
            {{2021, 12, 31}, {event_5, event_1}}                // "2021-12-31" : {"Fifth ! Event", "First 1234 Event"}
        };

        Database testing;
        testing.Add({2020, 12, 30}, event_1);
        testing.Add({2020, 12, 30}, event_2);
        testing.Add({2020, 12, 30}, event_2);
        testing.Add({2020, 12, 30}, event_3);
        testing.Add({2020, 12, 30}, event_3);

        testing.Add({2019, 12, 30}, event_1);
        testing.Add({2019, 12, 30}, event_1);
        testing.Add({2019, 12, 30}, event_3);
        testing.Add({2019, 12, 30}, event_3);

        testing.Add({0, 1, 1}, event_4);
        testing.Add({0, 1, 1}, event_4);
        testing.Add({0, 1, 1}, event_5);
        testing.Add({0, 1, 1}, event_5);

        testing.Add({2021, 12, 31}, event_5);
        testing.Add({2021, 12, 31}, event_5);
        testing.Add({2021, 12, 31}, event_1);
        testing.Add({2021, 12, 31}, event_1);

        AssertEqual(testing.GetAllData(), expected, "Class Database Method Add #2:");
    }
}


void TestClassDBPrint() {
    {   // Testing Print function to two dates
        Database db;
        const string input = "2020-01-01 Happy New Year!!!\n2021-01-01 Happy New Year!!! AGAIN ^&^\n";
        ostringstream expected;

        db.Add({2020, 1, 1}, "Happy New Year!!!");
        db.Add({2021, 1, 1}, "Happy New Year!!! AGAIN ^&^");
        db.Print(expected);

        AssertEqual(input, expected.str(), "Class Database Method Print #1:");
    }
    {   // Testing Print function to one date with repetitions
        Database db;
        ostringstream expected;
        const string input = "2020-01-01 This* Is Still NY\n2020-01-01 Just have FUN!@\n";

        db.Add({2020, 1, 1}, "This* Is Still NY");
        db.Add({2020, 1, 1}, "Just have FUN!@");
        db.Print(expected);

        AssertEqual(input, expected.str(), "Class Database Method Print #2:");
    }
    {   // Testing Add function to two dates with reverse insertion order
        Database db;
        ostringstream expected;
        const string input = "2020-01-01 New Yeeeeear!!!\n2021-12-31 Pre~ New Year\n";

        db.Add({2021, 12, 31}, "Pre~ New Year");
        db.Add({2020, 1, 1}, "New Yeeeeear!!!");
        db.Print(expected);

        AssertEqual(input, expected.str(), "Class Database Method Print #3:");
    }
    {   // Testing Add function to two dates with repetitions and two events
        Database db;
        ostringstream expected;
        const string input = "2020-01-01 EVENT#1\n2020-01-01 XXX()\n2021-01-01 NY!\n";

        db.Add({2021, 1, 1}, "NY!");
        db.Add({2020, 1, 1}, "EVENT#1");
        db.Add({2020, 1, 1}, "EVENT#1");
        db.Add({2020, 1, 1}, "XXX()");
        db.Add({2020, 1, 1}, "EVENT#1");
        db.Print(expected);

        AssertEqual(input, expected.str(), "Class Database Method Print #4:");
    }
}


// Side Function for testing Class Datebase, Method Datebase::RemoveIf:
int Del (Database& db, const string& input) {
    // Function modeling call of Del in terminal
        istringstream is (input);
        auto condition = ParseCondition(is);
        auto predicate = [condition](const Date &date, const string &event) {
            return condition->Evaluate(date, event);
        };

        return db.RemoveIf(predicate);
}


// Testing Class Datebase, Method Datebase::Del:
void TestClassDBDel() {
    {   // Testing RemoveIf method. Delete one date
        Database db;
        ostringstream input;

        db.Add({2020, 1, 1}, "NY!!!");
        db.Add({2022, 12, 31}, "Pre ~~ NY!");

        AssertEqual(0, Del(db, R"(event == "NOTHING")"), "Class Database Method Del #1: Nothing to remove");
        AssertEqual(1, Del(db, R"(date == "2020-01-01")"), "Class Database Method Del #2: Remove by date");

        db.Print(input);

        AssertEqual("2022-12-31 Pre ~~ NY!\n", input.str(), "Class Database Method Del #3: Right Print after Remove");
    }
    {   // Testing RemoveIf method. Delete two dates
        Database db;
        ostringstream input;

        db.Add({2020, 6, 1}, "1st of June");
        db.Add({2021, 7, 8}, "8th of July");
        db.Add({2021, 7, 8}, "Someone's birthday");

        AssertEqual(2, Del(db, R"(date == "2021-07-08")"), "Class Database Method Del #1: Remove by date, 2 entries");

        db.Print(input);

        AssertEqual("2020-06-01 1st of June\n", input.str(), "Class Database Method Del #2: Right Print after Remove");
    }
    {   // Testing RemoveIf method. Delete 3 dates. Hard condition
        Database db;
        ostringstream input;

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

        AssertEqual(3, Del(db, R"(date < 2017-01-01 AND (event == "holiday" OR event == "sport event"))"), "Class Database Method Del #1: Remove by date, 3 entries");

        db.Print(input);
        AssertEqual("0001-01-01 Jesus Birth\n2016-12-30 Some stupid shit\n2016-12-31 New Year\n2017-01-01 Live plz\n2020-08-07 holiday\n2020-08-07 sport event\n2020-08-07 Someone's birthday\n", input.str(), "Class Database Method Del #2: Remove by date, 3 entries. Right Print after Remove");
    }
    {   // Testing RemoveIf method. Delete ALL dates. No condition
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

        AssertEqual(10, Del(db, R"()"), "Class Database Method Del #1: Remove All, 10 entries");

        db.Print(out);
        AssertEqual("", out.str(), "Class Database Method Del #1: Remove by date, 10 entries. Right Print after Remove");
    }
    {
         Database db;
        ostringstream out;

        db.Add({1, 1, 1}, "Jesus Birth");               // Del
        db.Add({1, 1, 2}, "Jesus Birth");               // Del

        AssertEqual(2, Del(db, R"()"), "Class Database Method Del #1: Remove All, 2 entries");

        db.Add({1, 1, 1}, "Jesus Birth");               // Del
        db.Add({1, 1, 2}, "Jesus Birth");               // Del

        AssertEqual(2, Del(db, R"()"), "Class Database Method Del #2: Remove All, 2 entries !");

        db.Add({1, 1, 1}, "Jesus Birth");
        db.Add({1, 1, 2}, "Jesus Birth");

        db.Print(out);
        AssertEqual("0001-01-01 Jesus Birth\n0001-01-02 Jesus Birth\n", out.str(), "Class Database Method Del #3: Remove by date, 2 entries");
    }
    {
         Database db;
        ostringstream out;

        db.Add({1, 1, 1}, "Jesus Birth");               // Del
        db.Add({1, 1, 1}, "Judah Birth");
        db.Add({1, 1, 2}, "Jesus Birth");               // Del

        AssertEqual(2, Del(db, R"(event == "Jesus Birth")"), "Class Database Method Del #1: Remove All, 2 entries");

        db.Add({1, 1, 1}, "Jesus Birth");               // Del
        db.Add({1, 1, 1}, "Judah Birth");
        db.Add({1, 1, 2}, "Jesus Birth");               // Del

        // Doesn't Work!!!!!
        // Ban with Remove_if statue for new main container. Fix it!!!!
        AssertEqual(2, Del(db, R"(event == "Jesus Birth")"), "Class Database Method Del #2: Remove All, 2 entries !");

        db.Add({1, 1, 1}, "Jesus Birth");
        db.Add({1, 1, 2}, "Jesus Birth");

        db.Print(out);
        AssertEqual("0001-01-01 Judah Birth\n0001-01-01 Jesus Birth\n0001-01-02 Jesus Birth\n", out.str(), "Class Database Method Del #3: Remove by date, 2 entries");
    }

}


// Side Function for testing Class Datebase, Method Datebase::FindIf:
string Find (Database& db, const string& input) {
    // Function modeling call of Del in terminal
    istringstream is(input);
    ostringstream os;

    auto condition = ParseCondition(is);
    auto predicate = [condition](const Date &date, const string &event) {
        return condition->Evaluate(date, event);
    };

    const auto entries = db.FindIf(predicate);
    for (const auto& entry : entries) {
        os << entry << endl;
    }

    os << entries.size();
    return os.str();
}


// Testing Class Datebase, Method Datebase::Find:
void TestClassDBFind() {
    {   // Testing with basics FindIf
        Database db;
        const string input_1 = "2020-01-01 Some New Y Again(\n1",
                     input_2 = "2017-01-07 Stuff_\n2020-01-01 Some New Y Again(\n2",
                     input_3 = "2020-01-01 Some New Y Again(\n1";

        db.Add({2020, 1, 1}, "Some New Y Again(");
        db.Add({2017, 1, 7}, "Stuff_");

        AssertEqual(input_1, Find(db, "date == 2020-01-01"), "Class Database Method Find #1:");

        AssertEqual(input_2, Find(db, "date < 2020-01-31"), "Class Database Method Find #2:");

        AssertEqual(input_3, Find(db, R"(event != "Stuff_")"), "Class Database Method Find #3:");
    }
    {
        Database db;
         const string input_1 = "2020-01-01 N Y ON1\n2020-01-07 ZZZZZ\n2",
                      input_2 = "2020-01-01 N Y ON1\n1",
                      input_3 = "0";

        db.Add({2020, 1, 1}, "N Y ON1");
        db.Add({2020, 1, 1}, "N Y TW2");
        db.Add({2020, 1, 7}, "ZZZZZ");

        AssertEqual(input_1, Find(db, R"(date == 2020-01-07 OR event == "N Y ON1")"), "Class Database Method Find #1:");

        AssertEqual(input_2, Find(db, R"(date == 2020-01-01 AND event == "N Y ON1")"), "Class Database Method Find #2:");

        AssertEqual(input_3, Find(db, R"(date == 2017-01-09 AND event == "N Y ON1")"), "Class Database Method Find #3: Finds nothing");
    }
}


// Testing Class Datebase, Method Datebase::Last:
void TestClassDBLast() {
    Database db;
    db.Add({2017, 1, 1}, "new year");
    db.Add({2017, 1, 7}, "xmas");
    {
        try {
            istringstream is("2016-12-31");
            db.Last(ParseDate(is));
            Assert(false, "last, found no entries");
        } catch (...){
            Assert(true, "last, found no entries");

        }
    }
    {
        ostringstream os;
        istringstream is("2017-01-02");

        os << db.Last(ParseDate(is));

        AssertEqual("2017-01-01 new year", os.str(), "greater than date");
    }
    {
        ostringstream os;
        istringstream is("2017-01-01");

        os << db.Last(ParseDate(is));

        AssertEqual("2017-01-01 new year", os.str(), "eq to date");
    }
    {
        ostringstream os;
        istringstream is("2017-01-10");

        os << db.Last(ParseDate(is));

        AssertEqual("2017-01-07 xmas", os.str(), "greater than max date");
    }
}


// Some CUstom test that covers all commands:
void TestCustom() {
    {
        Database db;
        ostringstream input_1, input_2;
        const string print_expected_1 = "2020-12-01 First @ Event\n2020-12-01 Second @ Event\n2020-12-02 Third @ Event\n2020-12-02 Fourth @ Event\n2020-12-03 Fifth @ Event\n2020-12-03 Sixth @ Event\n",
                     print_expected_2 = "2020-11-30 Zero @ Event\n2020-12-01 First @ Event\n2020-12-02 Fourth @ Event\n2020-12-03 ~Sixth @ Event\n";

        db.Add({2020, 12, 1}, "First @ Event");
        db.Add({2020, 12, 1}, "Second @ Event");
        db.Add({2020, 12, 2}, "Third @ Event");
        db.Add({2020, 12, 2}, "Fourth @ Event");
        db.Add({2020, 12, 3}, "Fifth @ Event");
        db.Add({2020, 12, 3}, "Sixth @ Event");

        db.Print(input_1);

        AssertEqual(print_expected_1, input_1.str(), "Custom tests #1: Add, then Print");

        AssertEqual(1, Del(db, R"(event == "something" OR event == "Third @ Event")" ), "Custom tests #2: First Del");    //Del 2020-12-02 Fourth @ Event

        AssertEqual(1, Del(db, R"(date == "2020-12-03" AND event != "Fifth @ Event")" ), "Custom tests #3: Second Del");   //Del 2020-12-03 Sixth @ Event

        const DBType expected_map_1 = {
            {{2020, 12, 1}, {"First @ Event", "Second @ Event"}},
            {{2020, 12, 2}, {"Fourth @ Event"}},
            {{2020, 12, 3}, {"Fifth @ Event"}},
        };
        AssertEqual(db.GetAllData(), expected_map_1, "Custom tests #4: Checking Hole Database");

        db.Add({2020, 11, 30}, "Zero @ Event");

        AssertEqual("2020-12-03 Fifth @ Event\n1", Find(db, R"(date >= 2020-12-3)"), "Custom tests #5: Add new on pos zero, then Find");

        AssertEqual("2020-12-03 Fifth @ Event", db.Last({2020, 12, 4}), "Custom tests #6: Last after end of map");

        try {

            db.Last({2020, 11, 3});
            AssertEqual("ERROR", "", "Custom tests #7: Should throw exception");

        }
        catch(invalid_argument& e) {

            stringstream output;
            output << e.what();
            AssertEqual("2020-11-03", output.str(), "Custom tests #8: Only if no Exception");
        }

        AssertEqual("2020-12-02 Fourth @ Event", db.Last({2020, 12, 2}), "Custom tests #9: Last, that equals");

        AssertEqual("2020-12-01 Second @ Event", db.Last({2020, 12, 1}), "Custom tests #10: Last, that equals, but first in map");

        db.Add({2020, 12, 3}, "~Sixth @ Event");
        AssertEqual("2020-12-03 ~Sixth @ Event", db.Last({2020, 12, 3}), "Custom tests #11: Last, after adding in map");

        AssertEqual(2, Del(db, R"((event == "Second @ Event" AND event != "First @ Event") OR (event == "Fifth @ Event" AND date == 2020-12-3))" ), "Custom tests #11: Third Del"); // Del 2020-12-01 Second @ Event
                                                                                                                                                                                    // Del 2020-12-03 Fifth @ Event
        const DBType expected_map_2 = {
            {{2020, 11, 30}, {"Zero @ Event"}},
            {{2020, 12, 1}, {"First @ Event"}},
            {{2020, 12, 2}, {"Fourth @ Event"}},
            {{2020, 12, 3}, {"~Sixth @ Event"}},
        };
        AssertEqual(db.GetAllData(), expected_map_2, "Custom tests #12: Checking Hole Database");

        db.Print(input_2);
        AssertEqual(print_expected_2, input_2.str(), "Custom tests #13: Print after all commands");

        AssertEqual(4, Del(db, R"()"), "Custom tests #14: Fourth Del ALL");

        try {

            db.Last({2020, 11, 3});
            AssertEqual("ERROR", "", "Custom tests #15: Should throw exception");

        } catch(invalid_argument& e) {

            stringstream output;
            output << e.what();
            AssertEqual("2020-11-03", output.str(), "Custom tests #16: Only if no Exception");
        }
    }
}

void TestAll() {
    cerr << "------------------Tests-----------------------" << endl;
    TestRunner tr;

    tr.RunTest(TestClassDate, "Test_Class_Date");
    tr.RunTest(TestParseEvent, "Test_Function_Parse_Event");
    tr.RunTest(TestParseCondition, "Test_Function_Parse_Condition");
    tr.RunTest(TestEmptyNode, "Test_Class_EmptyNode");
    tr.RunTest(TestDateComparisonNode, "Test_Class_DateComparisonNode");
    tr.RunTest(TestEventComparisonNode, "Test_Class_EventComparisonNode");
    tr.RunTest(TestClassDBAdd, "Test_Class_Datebase_ADD_PRINT");
    tr.RunTest(TestClassDBPrint, "Test_Class_Datebase_ADD_PRINT");
    tr.RunTest(TestClassDBDel, "Test_Class_Datebase_Del");
    tr.RunTest(TestClassDBFind, "Test_Class_Datebase_Find");
    tr.RunTest(TestClassDBLast, "Test_Class_Datebase_Last");
    tr.RunTest(TestCustom, "Test_Custom");

    cerr << "----------------------------------------------" << endl << endl;
}
