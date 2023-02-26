with open("in.txt", "r") as inp:
    T, _raw1, _raw2 = inp.read().strip().split('\n')
    T = int(T)
    a, b = [*map(int, _raw1.split(' '))]
    values = [*map(int, filter(lambda x: x, _raw2.split(' ')))]

found = False
m = 0

for value in values:
    m |= (1 << value)

for value in values:
    if m & (1 << (T-value)):
        found = True
        break

for i in range(a, b):
    if m & (1 << i):
        print(i)

if found:
    print("FOUND")
