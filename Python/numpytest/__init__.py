import time
import numpy as np

a = []
b = []
for i in range(1, 10241024):
    a.append(i)
    b.append(10241024 - i)

start_time = time.time()
c = []
for i in range(len(a)):
    c.append(a[i] * b[i])
end_time = time.time()
exec_time = end_time - start_time
print("python exec", exec_time)


npa = np.array(a)
npb = np.array(b)
start_time = time.time()
npc = npa * npb
end_time = time.time()
exec_time = end_time - start_time
print("python numpy exec", exec_time)
