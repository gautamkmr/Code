import random
import sys


h=0
t=0
for i in range(int(sys.argv[1])):
   c = random.randint(0,1)
   if c == 1:
      h = h +1
   else:
      t = t + 1

print("Head:", h)
print("Tail:", t)

