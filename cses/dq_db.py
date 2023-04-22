from subprocess import Popen, PIPE

p = Popen(['./a.out'], stdout=PIPE, stdin=PIPE, stderr=PIPE)

data = "3\n"
a = ''.join([str(i) for i in range(1,1000)])

for i in range(3):
    data += (str(i+1) + "\n")

out, err = p.communicate(input=data.encode('ascii'))
cpp = out.decode()

print(cpp)

for i in range(100):
    try:
        assert cpp[i] == a[i]
    except AssertionError:
        print("Conflict at %d:" % (i), cpp[i], a[i])
    except:
        raise
