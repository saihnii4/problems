a = []

while 42 not in a:
    a.append(int(input()))

del a[-1]

for num in a:
    print(num)
