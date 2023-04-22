rng = [*range(1, 100)]

with open("input.txt", "w") as buf:
    for (x, y) in zip(rng, rng[1:]):
        buf.write('%d %d\n' % (x, y))

