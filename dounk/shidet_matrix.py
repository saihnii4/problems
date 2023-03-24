N = int(input())
A = []
for _ in range(N):
    A.append([*map(int, input().split(" "))])

sum = 0
misc = 0
for i in range(N):
    for j in range(N):
        if not i: misc += A[0][j]
        sum += A[i][j]

if sum % N != 0 and sum % misc != 0:
    print("NO")
else:
    for i in range(N):
        misc -= A[i][i]

    if misc == 0:
        print("YES")
    else:
        print("NO")


