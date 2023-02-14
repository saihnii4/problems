with open("in.txt", "r") as inp:
    T, _raw1, _raw2 = inp.read().strip().split('\n')
    T = int(T)
    a, b = [*map(int, _raw1.split(' '))]
    values = [*map(int, filter(lambda x: x, _raw2.split(' ')))]

found = False

for value in values:
    for fuckme in values:
        if value + fuckme == T:
            found = True

print("LESSGO" if found else "FUCK")
