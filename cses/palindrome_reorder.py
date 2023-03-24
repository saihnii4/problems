# wth
word = input()

def main():
    c = ""
    e = ''
    d = False

    for letter in set(word):
        if word.count(letter) & 1 != 0:
            if d:
                print("NO SOLUTION")
                return
            d = True
            e = letter*word.count(letter)
            continue 
        c = c + "".join([letter for _ in range(word.count(letter)//2)])

    c = c + e + c[::-1]

    return c

print(main())
