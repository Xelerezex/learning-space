#include "search_server.h"
#include "parse.h"
#include "generators.h"


chrono::milliseconds random_time()
{
    return 150ms;
}


void TestSearchServer(vector<pair<istream*, ostream*>> streams)
{
    LOG_DURATION("Total");
    SearchServer srv(*(streams.front().first));
    for (auto& [input, output] : IteratorRange(begin(streams) + 1, end(streams)))
    {
        this_thread::sleep_for(random_time());

        if (!output)
        {
            srv.UpdateDocumentBase(*input);
        }
        else
        {
            srv.AddQueriesStream(*input, *output);
        }
    }
}

void TestSerpFormat ()
{
    istringstream docs_input(
        "london is the capital of great britain\n\
         i am travelling down the river"
    );

    istringstream queries(
        "london\n\
         the"
    );

    ostringstream expected(
        "london: {docid: 0, hitcount: 1}\n\
         the: {docid: 0, hitcount: 1} {docid: 1, hitcount: 1}\n"
    );

    ostringstream empty;
    ostringstream output;

    vector<pair<istream*, ostream*>> streams {
        {&docs_input, &empty},
        {&queries, &output},
    };


    TestSearchServer(streams);
    ASSERT_EQUAL(output.str(), expected.str());
}

void TestTop5 ()
{
    istringstream docs_input(
        "milk a\n\
         milk b\n\
         milk c\n\
         milk d\n\
         milk e\n\
         milk f\n\
         milk g\n\
         water a\n\
         water b\n\
         fire and earth"
    );

    istringstream queries(
        "milk\n\
         water\n\
         rock"
    );

    ostringstream expected(
        "milk: {docid: 0, hitcount: 1} {docid: 1, hitcount: 1} {docid: 2, hitcount: 1} {docid: 3, hitcount: 1} {docid: 4, hitcount: 1}\n\
         water: {docid: 7, hitcount: 1} {docid: 8, hitcount: 1}\n\
         rock:\n"
    );

    ostringstream empty;
    ostringstream output;

    vector<pair<istream*, ostream*>> streams {
        {&docs_input, &empty},
        {&queries, &output},
    };


    TestSearchServer(streams);
    ASSERT_EQUAL(output.str(), expected.str());
}

void CuncurrencyTest()
{
    const vector<string>& docs = generate_random_documents(5'000, 500, 1'500, 99, 42);
    vector<string> docs1(docs.begin(),         docs.begin() + 2'500);
    vector<string> docs2(docs.begin() + 2'500, docs.end());
    istringstream input1(Join('\n', docs1));
    istringstream input2(Join('\n', docs2));


    ostringstream os1;
    ostringstream os2;

    vector<pair<istream*, ostream*>> streams {
        {&input1, &os1},
        {&input2, &os2},
    };

    TestSearchServer(streams);
}

int main()
{
    TestRunner tr;
    RUN_TEST(tr, TestSerpFormat);

    RUN_TEST(tr, TestTop5);


    RUN_TEST(tr, CuncurrencyTest);
}
