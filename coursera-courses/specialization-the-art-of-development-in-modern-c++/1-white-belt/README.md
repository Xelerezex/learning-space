# Основы разработки на C++: белый пояс

![alt-текст](https://github.com/Hitoku/basics-of-c-plus-plus-development-white-belt/blob/master/img.jpg)

| Basic Info | Course 1 of 5 in the [Искусство разработки на современном C++ Specialization](https://www.coursera.org/learn/c-plus-plus-white)|
| ------------- | ------------- |
| Level | Intermediate |
| Language | Russian |
| How To Pass | Pass all graded assignments to complete the course. |
| User Ratings | Average User Rating 4.8 [See what learners said](https://www.coursera.org/learn/c-plus-plus-white#ratings)|

* WEEK 1 ---> [Open](https://github.com/Hitoku/basics-of-c-plus-plus-development-white-belt/tree/master/Week_1)
* WEEK 2 ---> [Open](https://github.com/Hitoku/basics-of-c-plus-plus-development-white-belt/tree/master/Week_2)
* WEEK 3 ---> [Open](https://github.com/Hitoku/basics-of-c-plus-plus-development-white-belt/tree/master/Week_3)
* WEEK 4 ---> [Open](https://github.com/Hitoku/basics-of-c-plus-plus-development-white-belt/tree/master/Week_4)
* WEEK 5 ---> [Open](https://github.com/Hitoku/basics-of-c-plus-plus-development-white-belt/tree/master/Week_5)

[Основы разработки на C++: жёлтый пояс](https://github.com/Hitoku/basics-of-c-plus-plus-development-yellow-belt)


# IN-WORK

# [C++: The White Belt](https://www.coursera.org/learn/c-plus-plus-white/)
by Moscow Institute of Physics and Technology & Yandex (in Russian language)


### Goals
- [ ] Get general understanding of modern `C++ -std=c++1y`es for Node.js (and piss off my JS mates, LOL)

### Summary
    ???

### Tools
* OS: ?
* Editor: ?
* Git:
    * git ?
    * hub for GitHub ?
* Compiler:
    * g++ ?


### Week #1: Intro to C++
1. Types overview
    * `int`
    * `double`
    * `bool`
    * `char`
    * `string`
    * `vector<int> var_name`
    * `map<int, string> var_name`
    * `map<string, int> var_name`
2. Operation with builtin primitives
3. Operations with builtin containers (string & vector)
    * algorithm standard library
    * `count(begin(var_name), end(var_name), length(var_name));`
    * `sort(begin(var_name), end(var_name));`
4. Input/Output (`cin`, `cout`);
    * `cin >> x >> y;`
    * `cout << x + y << endl;`
5. Loops, conditions, comments
    * `for (auto x : var_name) {cout << x;}`
6. Usge of semicolon
7. Eclipse (Don't work well on macOS High Sierra)
8. Programming Assignment: `A+B` (see `0xA+B/README.md`)
9. Operations: assignment
    * concept of full deep copying
10. Operations: division, incrementation
    * Division is type dependent
    * `+=`, `-=`, `*=` & `/=`
    * `++i`, `i++`, `--i`, `i--` and difference between pre & post increments
11. Logical operations
    * `==` operator
    * strings are compared lexicographically
    * maps & vectors could be compared with `==` operator
    * Logical NO (negation) operator `!`
    * Logical AND (conjunction) operator `&&`
    * Logical OR (disjunction) operator `||`
12. Programming Assignment: `Min_String` (see `1xMin_String/README.md`)
13. Programming Assignment: `Equation` (see `2xEquation/README.md`)
14. Principles of testing
    * Create a test plan
    * Cover the edge cases
    * Cover the normal cases
15. Conditional operators and loops
    * `if`
    * `while`, `do {} while`
    * `for`, `for (auto : i)`
    * `map<string, int> dict = { {"alpha", 1}, ... };`
    * `for (auto : i) {i.first; i.second}`
    * break;
16. Programming Assignment: `Division` (`3xDivision/README.md`)
17. Programming Assignment: `Price_Calculation` (`Week-1/4xPrice_Calculation/README.md`)

### Week #2: Functions & Containers
1. Passing parameters by values
2. Programming Assignment: Factorial (`Week-2/0xFactorial/README.md`)
3. Programming Assignment: IsPalindrom (`Week-2/1xIsPalindrom/README.md`)
4. Programming Assignment: PalindromFilter (`Week-2/2xPalindromFilter/README.md`)
5. Passing parameters by reference (`&` symbol before type declaration)
    * `int myfn(int& n)`
    * `int&, string&, map<int, int>&...`
6. Passing parameters by a constant link
    * Constant link avoids copying of value (good for large objects)
    * Constant link protects object from [accidental] mutations
    * `const`
    * `using namespace std::chrono`


### Links

* [Fluent C++](https://www.fluentcpp.com)
