sum = 0
d = {"blue": "b", "green": "g", "red": "r"}
d2 = {"r" : 12, "g": 13, "b": 14}

with open("in2") as buf:
    lines = [*filter(lambda x: x, buf.readlines())]

def check(x):
    if (d2[x[-1]] < int(x[:-1])):
        return False
    return True

def _preprocess(x):
    for line in x.strip().split(", "):
        yield line.split(" ")[0] + d[line.split(" ")[1]]

for line in lines:
    id, cases = line.split(":")
    cases = [*map(_preprocess, cases.split(";"))]
    _, id = id.split(" ")
    if all([*map(lambda case: all([*map(check, case)]), cases)]):
        sum += int(id)

print(sum)
