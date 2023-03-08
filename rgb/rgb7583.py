A = input()
i = 0

while A != '6174':
    c = sorted(A)
    d = int(''.join(c[::-1]))
    c = int(''.join(c))
    A = str(d - c)
    i += 1

print(i+1)
