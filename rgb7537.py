import itertools

n = int(input())
up_limit = n // 2
digits = len(str(up_limit))

l = ['4', '7']

flatten = lambda arr: *a for a in arr

a =[[[*itertools.permutations(('4', '7', '0'), i)] for i in range(digits)]]

print(a)

def main():
    if set(str(n)) == {'4', '7'}:
        print("YES")
        return

    for num in itertools.product(('4', '7', '0'), repeat=digits):
        if n % int(''.join(num)) == 0:
            print("YES")
            return
    print("NO")

main()
