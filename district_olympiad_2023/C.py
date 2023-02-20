from ctypes import wstring_at
import itertools

a, b = [*map(int, input().split(" "))]

c = [*itertools.product(('0', '1'), repeat=a*b)]

def _hash(arr):
    hash = 0

    for i in range(len(arr)):
        lb_diag = i + b - 1
        rb_diag = i + b + 1
        ru_diag = i - b + 1
        lu_diag = i - b - 1

        n = i + 1
        p = i - 1

        u = i - a
        d = i + a

        if p < 0:
            p = None

        if i//3 == 0:
            u = i + a*(b-1)
            if i % a != 0:
                lu_diag = u - 1
            else:
                lu_diag = None

            if (i+1)%a != 0:
                ru_diag = u + 1
            else:
                ru_diag = None

        if i//3 == b-1:
            d = i % b
            if i % a != 0:
                lb_diag = d - 1
            else:
                lb_diag = None

            if (i+1) % a != 0:
                rb_diag = d + 1
            else:
                rb_diag = None

        if i % a == 0:
            lb_diag = None
            lu_diag = None
            p = None

        if (i+1) % a == 0:
            ru_diag = None
            n = None
            rb_diag = None

        print(i)
        #
        # print("{} {} {}\n{} {} {}\n{} {} {}".format(
        #     arr[lu_diag] if lu_diag is not None else -1,
        #     arr[u] if u is not None else -1,
        #     arr[ru_diag] if ru_diag is not None else -1,
        #     arr[p] if p is not None else -1,
        #     arr[i],
        #     arr[n] if n is not None else -1,
        #     arr[lb_diag] if lb_diag is not None else -1,
        #     arr[d] if d is not None else -1,
        #     arr[rb_diag] if rb_diag is not None else -1))
        # print("\n\n")

        map = ["Up: ", "Down: ", "Previous: ", "Next: ", "LB: ", "LU: ", "RU: ", "RB: "]

        for i, el in enumerate([u, d, p, n, lb_diag, lu_diag, ru_diag, rb_diag]):
            if el is None:
                continue
            hash += (i+1)*arr[el]
        print()

    return hash


s1 = [0, 1, 1, 0, 1, 0, 0, 0, 0]
s2 = [1, 1, 0, 1, 0, 0, 0, 0, 0]

print(_hash(s1), _hash(s2))
print(_hash(s1) == _hash(s2))
