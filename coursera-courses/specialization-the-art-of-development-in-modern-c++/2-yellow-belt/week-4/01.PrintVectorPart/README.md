## Print Vector Part


Напишите функцию *PrintVectorPart*, принимающую вектор целых чисел *numbers*, выполняющую поиск первого отрицательного числа в нём и выводящую в стандартный вывод все числа, расположенные левее найденного, в обратном порядке. Если вектор не содержит отрицательных чисел, выведите все числа в обратном порядке.

```cpp
void PrintVectorPart(const vector<int>& numbers);
```
#### Example:

```cpp
int main() {
  PrintVectorPart({6, 1, 8, -5, 4});
  PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
  PrintVectorPart({6, 1, 8, 5, 4});
  return 0;
}
```

##### Output:

```commandline
8 1 6
4 5 8 1 6
```
