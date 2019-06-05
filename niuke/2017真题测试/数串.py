import sys
from functools import cmp_to_key
 
def mycmp(x, y):
    if x + y > y + x:        return 1
    elif x == y:        return 0
    else:        return -1
 
# for i, v in enumerate(sys.stdin.readlines()):
#     if i % 2 == 1:
v = sys.stdin.readline()
v = v.strip().split()
v.sort(key=cmp_to_key(mycmp), reverse=True)
print("".join(v).lstrip("0") or "0")