import functools
n, k = [*map(int, input().split(" "))]
nums = [*map(int, input().split(" "))]
val = functools.reduce(lambda acc, x: acc | (1 << x), nums, 0)

count = 0

for i in nums:
    b = val ^ (1 << i)
    print(i, b, abs(k -i), b & abs(k-i))
    if b & abs(k - i):
        count += 1

print(count)
