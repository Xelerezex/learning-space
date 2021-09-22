#include "test_runner.h"
#include "profile.h"


using namespace std;


void TestBasic();
void TestFromAssignment();
void TestAll();
void TestHard();


long long int MaximumPairwiseProduct(vector<int> &data) {
    long long int first = 0, second = 0;
    auto iter_first = data.begin();

    for (auto iter = data.begin(); iter != data.end(); ++iter) {
        if (first <= *iter) {
            first = *iter;
            iter_first = iter;
        }
    }

    for (auto iter = data.begin(); iter != data.end(); ++iter) {
        if (second <= *iter && iter != iter_first) {
            second = *iter;
        }
    }

    return first * second;
}


int main() {
    TestAll();
}


void TestBasic() {
    vector<int> vect;
    string number;
    string PATH = "/home/person/Документы/__repo__/learning-space/coursera-courses/specialization-algorithms-data-structures/01-algorithmic-toolbox/week-1/02-maximum-pairwise-product/Tests/test-data-0.txt";
    ifstream in(PATH);

    while (getline(in, number)) {
        vect.push_back(stoi(number));
    }

    ASSERT_EQUAL(MaximumPairwiseProduct(vect), 20);
}


void TestFromAssignment() {
    {
        vector<int> vect;
        string number;
        string PATH = "/home/person/Документы/__repo__/learning-space/coursera-courses/specialization-algorithms-data-structures/01-algorithmic-toolbox/week-1/02-maximum-pairwise-product/Tests/test-data-1.txt";
        ifstream in(PATH);

        while (getline(in, number)) {
            vect.push_back(stoi(number));
        }

        ASSERT_EQUAL(MaximumPairwiseProduct(vect), 6);
    }
    {
        vector<int> vect;
        string number;
        string PATH = "/home/person/Документы/__repo__/learning-space/coursera-courses/specialization-algorithms-data-structures/01-algorithmic-toolbox/week-1/02-maximum-pairwise-product/Tests/test-data-2.txt";
        ifstream in(PATH);

        while (getline(in, number)) {
            vect.push_back(stoi(number));
        }

        ASSERT_EQUAL(MaximumPairwiseProduct(vect), 196);
    }
}


void TestHard() {
    {
        vector<int> vect;
        string number;
        string PATH = "/home/person/Документы/__repo__/learning-space/coursera-courses/specialization-algorithms-data-structures/01-algorithmic-toolbox/week-1/02-maximum-pairwise-product/Tests/test-data-3.txt";
        ifstream in(PATH);

        while (getline(in, number)) {
            vect.push_back(stoi(number));
        }

        ASSERT_EQUAL(MaximumPairwiseProduct(vect), 39'999'800'000);
    }
}


void TestAll() {
    cerr << "------------------Tests-----------------------" << endl;
    TestRunner tr;

    RUN_TEST(tr, TestBasic);
    RUN_TEST(tr, TestFromAssignment);
    RUN_TEST(tr, TestHard);

    cerr << "----------------------------------------------" << endl << endl;
}
