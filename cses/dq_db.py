from subprocess import Popen, PIPE

p = Popen(['./a.out'], stdout=PIPE, stdin=PIPE, stderr=PIPE)

data = "100\n"
a = ''.join([str(i) for i in range(1,1000)])

for i in range(100):
    data += (str(i+1) + "\n")

out, err = p.communicate(input=data.encode('ascii'))
cpp = out.decode()

for i in range(100):
    assert cpp[i] == data[i]
