# very bad code

n = int(input())
data = sorted(tuple([(x, y, i) for i, (x, y) in enumerate([*(map(int, input().split(' ')) for _ in range(n))])]))

bruh = [-1 for _ in range(n)]

room = 1
while len(data) > 0:
    cmp = data[0]
    garbage = []
    bruh[data[0][2]] = room
    for i, item in enumerate(data[1:]):
        if item[0] <= cmp[1]:
            continue

        cmp = item
        bruh[i+1] = room
        garbage.append(i+1)

    del data[0]
    n = 1
    for i in garbage:
        del data[i-n]
        n += 1

    room += 1

print(max(bruh))
print(bruh)
