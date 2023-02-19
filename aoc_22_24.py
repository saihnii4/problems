with open("aoc_24.txt") as buf:
    lines = buf.read().split('\n')

grid = []

for line in lines[1:-2]:
    row = []
    for i, x in enumerate(line[1:-1]):
        if x == "^":
            row.append(-2)
        elif x == ">":
            row.append(1)
        elif x == "<":
            row.append(-1)
        elif x == "v":
            row.append(2)
        else:
            row.append(0)
    grid.append(row)


for i, row in enumerate(grid):
    for j, val in enumerate(row):
        if row == -1:
            # cont
