## Find Nearest Element

Напишите функцию *FindNearestElement*, для множества целых чисел *numbers* и данного числа *border* возвращающую итератор на элемент множества, ближайший к *border*. Если ближайших элементов несколько, верните итератор на наименьший из них.

```cpp
set<int>::const_iterator FindNearestElement(
    const set<int>& numbers,
    int border);
// set<int>::const_iterator —
// тип итераторов для константного множества целых чисел
```

#### Example:

```cpp
int main() {
  set<int> numbers = {1, 4, 6};
  cout <<
      *FindNearestElement(numbers, 0) << " " <<
      *FindNearestElement(numbers, 3) << " " <<
      *FindNearestElement(numbers, 5) << " " <<
      *FindNearestElement(numbers, 6) << " " <<
      *FindNearestElement(numbers, 100) << endl;
      
  set<int> empty_set;
  
  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}
```

##### Output:

```commandline
1 4 4 6 6
1
```
