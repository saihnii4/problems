# C++ is freaking out idk why
a = input().strip()
if int(a) == sum([*map(lambda x: int(x)**3, a)]):
    print("YES")
else:
    print("NO")
