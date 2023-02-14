inp = [*input()]
i = 0

for j, val in enumerate(inp):
    if val == '"':
        if i & 1:
            inp[j] = '_'
        else:
            inp[j] = '*'
        i += 1

print(inp)
