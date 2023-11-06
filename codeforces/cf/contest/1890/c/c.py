T=int(input())
def good(s : str):
    for a, b in zip(s, s[::-1]):
        if a == b:
            return False
    return True
def solve():
    n = input()
    a = input()
    if good(a):
        print("0\n")
        return
    

for _ in range(T):
    solve()
