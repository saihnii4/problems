import functools

d = {"blue": "b", "green": "g", "red": "r"}

with open("in2") as buf:
    lines = [*filter(lambda x: x, buf.readlines())]

def process(acc, case):
    for k, v in case.items():
        acc[k] = max(acc[k], v)
    return acc

def _preprocess(x):
    case = {}
    for line in x.strip().split(", "):
        case[d[line.split(" ")[1]]] = int(line.split(" ")[0])
    return case

if __name__ == "__main__":
    sum = 0
    for line in lines:
        _id, _cases = line.split(":")
        cases = [*map(_preprocess, _cases.split(";"))]
        _, id = _id.split(" ")
        maxima = functools.reduce(process, cases, {'r': -1e9, 'g': -1e9, 'b': -1e9}) # definitely didn't need to go that low on the lower bound but it work so whatever
        power = functools.reduce(lambda x, y: x * y, maxima.values())
        sum += power 
    print(sum)
