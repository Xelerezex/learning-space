s = int(input())
n1 = " программистов"
n2 = " программист"
n3 = " программиста"
if s >= 0:
  if s == 0:
    print(str(s) + n1)
  elif s % 100 >= 10 and s % 100 <= 20:
    print(str(s) + n1)
  elif s % 10 == 1:
    print(str(s) + n2)
  elif s % 10 >= 2 and s % 10 <= 4:
    print(str(s) + n3)
  else:
    print(str(s) + n1)
