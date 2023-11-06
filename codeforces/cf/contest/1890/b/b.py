T=int(input())
def good(s : str):
    for prev, next in zip(s, s[1:]):
        if prev == next:
            return False
    return True
def solve():
    input()
    a = input()
    b = input()
    if good(a):
        print("YES")
        return
    if not good(b):
        print("NO")
        return
    prefix = b[0]
    suffix = b[-1]
    for prev, next in zip(a, a[1:]):
        if prev != next:
            continue
        if prev == prefix or suffix == next:
            print("NO")
            return
    print("YES")
for _ in range(T):
    solve()
