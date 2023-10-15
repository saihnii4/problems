# original contest code. should've accounted for bounds smh
ans=[]
t=int(input())
def main():
    n, m = [*map(int, input().split(" "))]
    x = input()
    s = input()
    i = 0
    if s in x:
        ans.append(i)
        return
    for _ in range(6):
        x += x
        i += 1
        if s in x:
            ans.append(i)
            return
    ans.append(-1)
for _ in range(t):
    main()
print('\n'.join([*map(str,ans)]))
