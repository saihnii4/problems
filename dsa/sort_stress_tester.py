import random
N = ""
while not N.isdigit():
    N = input("N? >")
N = int(N)
input = [random.randint(0, int(1e9)) for _ in range(N)]
with open("sample", "w") as buf:
    buf.write("\n".join(map(str, input)) + '\n')
with open("answer", "w") as buf:
    buf.write("\n".join(map(str, sorted(input))))
