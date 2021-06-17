На вход подаётся полный путь к файлу относительно текущего каталога.

Проверьте есть ли такой файл (и файл ли это) и если он есть - выведите содержимое. Иначе выведите одну из 2 ошибок.

**Sample Input 1:**

```commandline
tmp/dir/text.txt
```


**Sample Output 1:**

```commandline
CONTENT:
Привет, Мир!
```


**Sample Input 2:**

```commandline
tmp/dir/
```


**Sample Output 2:**

```commandline
ERROR:
Это каталог, а не файл
```


**Sample Input 3:**

```commandline
tmp/text.txt
```


**Sample Output 3:**

```commandline
ERROR:
Файл не существует
```


