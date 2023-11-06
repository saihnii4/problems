t = int(input())
def solve():
    n = input()
    if n == 2:
        print("YES")
        return
    a = [*map(int, input().split(" "))]
    if len(set(a)) == 1:
       print("YES")
       return
    if len(set(a)) > 2:
        print("NO")
        return
    al = list(set(a))
    if abs(a.count(al[0])-a.count(al[1])) <= 1:
        print("YES")
        return
    print("NO")
for _ in range(t):
    solve();
