with open("aoc_in.txt") as buf:
    innards = buf.read().split("\n")

a = 2022
b = []

while a != 0:
    b.append(a % 5)
    a //= 5

def snafu_to_dec(num):
    val = 0

    for i, x in enumerate(num[::-1]):
        if x == "=":
            val += (-2)*(5**i)
        elif x == "-":
            val -= (5**i)
        else:
            val += (5**i)*int(x)

    return val

def dec_to_snafu(num):
    if num == 0: return 0

    b = []

    while num != 0:
        b.append(num % 5)
        num //= 5

    for i in range(len(b)):
        if b[i] == 3:
            b[i] = "="
            if i+1 == len(b):
                b.append(1)
            else:
                b[i+1] += 1
        elif b[i] == 4:
            b[i] = "-"
            if i+1 == len(b):
                b.append(1)
            else:
                b[i+1] += 1
        else:
            b[i] = int(b[i])

    return "".join(map(str, b[::-1]))

sum = 0

for line in innards:
    a = snafu_to_dec(line.strip())
    sum += a


print(sum)
print(dec_to_snafu(sum))
