a = 0
while a <= 100:
  a = int(input())
  if a > 100:
    break
  if a < 10:
    continue
  print(a)
