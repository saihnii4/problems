def main():
    s, n = [*map(int, input().split(" "))]
    cases = [[*map(int,input().split(" "))] for _ in range(n)]
    poss = [c[0] for c in cases]
    bon = [c[1] for c in cases]

    poss = {i: x for i, x in enumerate(poss)}
    bon = {i: x for i, x in enumerate(bon)}
    while poss != {}:
        change = 0
        # python doesn't allow us to modify the size of a dictionary so we need
        # to clean up after the loop
        clean_up = []

        for i, item in poss.items():
            if s > item:
                s += bon[i]
                poss[i] = -1
                clean_up.append(i)
                change += 1

        for b in clean_up:
            del poss[b]

        if poss != {} and change == 0:
            print("NO")
            return

    print("YES")

main()
