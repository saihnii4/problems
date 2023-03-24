import string
import random

T = 20000

input = [str(T)+"\n"]
output = []

letters = [*(string.ascii_lowercase+string.ascii_uppercase)]
random.shuffle(letters)

pad = random.randint(0, 5000)

for _ in range(T-pad):
    letters = [*(string.ascii_lowercase+string.ascii_uppercase)]
    random.shuffle(letters)

    assert (letters not in input)

    input.append("".join(letters) + "\n")
    output.append("OK")

for i in range(pad):
    input.append("hello\n")
    output.append("hello%s\n" % ("" if i == 0 else str(i)))

with open("in.txt", "w") as fu:
    fu.writelines(input)

with open("out.txt", "w") as bu:
    bu.writelines(output)

print("done")
