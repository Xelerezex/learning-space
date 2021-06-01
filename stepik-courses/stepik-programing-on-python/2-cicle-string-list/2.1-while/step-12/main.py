a = int(input())
b = int(input())
s = 1
k = 2
while s < k:
  if s % a == 0 and s % b == 0:
    k = s
  else:
    s = s + 1
    k = k + 1
print(s)
