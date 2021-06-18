my_list = set(input().split(", "))

for magazine in range(int(input())):
    for item in set(input().split(", ")):
        if item in my_list:
            my_list.remove(item)

print("YES" if len(my_list) == 0 else "NO")
