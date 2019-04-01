import math
def ok(n):
    k = int(n)
    return k == int(math.sqrt(k)) ** 2
s = input()
mx = -1
for i in range(0, 1 << len(s)):
    tmp = ""
    for j in range(0, len(s)):
        if i & (1 << j):
            tmp = tmp + s[j]
    if len(tmp) > 0 and tmp[0] != '0' and ok(tmp) == True:
        mx = max(mx, len(tmp))
if mx == -1:
    print(-1)
else:
    print(len(s)-mx)
