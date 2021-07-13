#ifndef TESTS_CPP
#define TESTS_CPP

//--> EDIT HERE
//----------------------ОПРЕДЕЛЕНИЕ КОНКРЕТНЫХ ТЕСТОВ---------------------------
//--------------------------IMPLEMENTATION--------------------------------------
#include "tests.h"

 /*
void TestingTest() {
    vector<vector<int>> input_data = {{0}};
    vector<int> expected = {0};

    AssertEqual(func(input_data), expected, "TestingTests");    
}*/

void LeetCodeTests() {
    {
        vector<vector<int>> input_data = {{1, 2, 3}, 
                                          {4, 5, 6}, 
                                          {7, 8, 9}};
        vector<int> expected = {1, 2, 4, 7, 5, 3, 6, 8, 9};

        AssertEqual(findDiagonalOrder(input_data), expected, "First LeetCode Test"); 
    }
    {
        vector<vector<int>> input_data = {{1, 2}, 
                                          {3, 4}};
        vector<int> expected = {1, 2, 3, 4};

        AssertEqual(findDiagonalOrder(input_data), expected, "Second LeetCode Test");
    }   
}

void Testing_N_N() {
    {   int a = -100'000, b = 100'000, c = 50'000, d = -66'777;
        vector<vector<int>> input_data = {
            {a, b, c, d}, 
            {d, a, d, c}, 
            {d, d, a, c},
            {d, d, c, a},
                                          };
        vector<int> expected = {a, b, d, d, a, c, d, d, d, d, d, a, c, c, c, a};

        AssertEqual(findDiagonalOrder(input_data), expected, "My First NxN Test");         
    }
    {
        vector<vector<int>> input_data = {
            {-1, -1, -1, -1}, 
            {-1, -1, -1, -1}, 
            {-1, -1, -1, -1},
            {-1, -1, -1, -1},
                                          };
        vector<int> expected = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};

        AssertEqual(findDiagonalOrder(input_data), expected, "My Second NxN Test");  
    }
}


void Testing_M_N() {
    {   int a = -100'000, b = 100'000, c = 50'000, d = -66'777;
        vector<vector<int>> input_data = {
            {a, b, c, d}, 
            {d, b, c, a},                                          
                                         };
        vector<int> expected = {a, b, d, b, c, d, c, a};

        AssertEqual(findDiagonalOrder(input_data), expected, "My First NxN Test");         
    }
    {   int a = -100'000, b = 100'000, c = 50'000, d = -66'777;
        vector<vector<int>> input_data = {
            {a, b},
            {c, d},
            {d, a},
            {d, b},
                                         };
        vector<int> expected = {a, b, c, d, d, a, d, b};

        AssertEqual(findDiagonalOrder(input_data), expected, "My First NxN Test");         
    }
}

void Testing_1_N_or_M_1() {
    {   int a = -100'000, b = 100'000, c = 50'000, d = -66'777;
        vector<vector<int>> input_data = {
            {a, b, c, d, 1, 1, 1, 1, 1, 1},            
                                         };
        vector<int> expected = {a, b, c, d, 1, 1, 1, 1, 1, 1};

        AssertEqual(findDiagonalOrder(input_data), expected, "My First NxN Test");         
    }
    {   int a = -100'000, b = 100'000, c = 50'000, d = -66'777;
        vector<vector<int>> input_data = {
            {a},
            {b},
            {c},
            {d},
            {1},
            {1},
            {1},
            {1},
            {1},
            {1},
                                         };
        vector<int> expected = {a, b, c, d, 1, 1, 1, 1, 1, 1};

        AssertEqual(findDiagonalOrder(input_data), expected, "My First NxN Test");         
    }
}

void TestAll(){
    unsigned counter = 0;
    TestRunner tr;
    //tr.RunTest(TestingTest, to_string(++counter) + ": LT Tests");
    tr.RunTest(LeetCodeTests, to_string(++counter) + ": LT Tests");
    tr.RunTest(Testing_N_N, to_string(++counter) + ": LT Tests");
    tr.RunTest(Testing_M_N, to_string(++counter) + ": LT Tests");
    tr.RunTest(Testing_1_N_or_M_1, to_string(++counter) + ": LT Tests");
}

//------------------------------------------------------------------------------
#endif
