import sys, os, io
input_fun = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline
input = lambda: input_fun().decode()
inpi = lambda: int(input())
inpil = lambda: list(map(int,input().split()))
printf = lambda x: sys.stdout.write(str(x) + '\n')

q = inpi()

for _ in range(q):
    pass