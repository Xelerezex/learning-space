Вам дана последовательность строк.

Выведите строки, содержащие **"cat"** в качестве подстроки хотя бы два раза.

**Примечание:**

Считать все строки по одной из стандартного потока ввода вы можете, например, так

```python
import sys

for line in sys.stdin:
    line = line.rstrip()
    # process line
```

Sample Input:
```commandline
catcat
cat and cat
catac
cat
ccaatt
```

Sample Output:
```commandline
catcat
cat and cat
```
