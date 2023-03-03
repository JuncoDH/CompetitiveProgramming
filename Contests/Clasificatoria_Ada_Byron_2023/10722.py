from decimal import Decimal, getcontext
import math, sys
input = sys.stdin.readline

MAX = 105

dp = {}

def f(d, used):
    ans = 0
    if d == 0:
        return 1
    if (d, used) in dp:
        return dp[(d, used)]
    if used == 0:
        ans = (b-1)*f(d-1, 0) + f(d-1, 1)
    else:
        ans = (b-2)*f(d-1, 0) + f(d-1, 1)
    dp[(d, used)] = ans
    return ans

while True:
    #try:
    x = input()
    x = x.split(' ')
    b = int(x[0])
    d = int(x[1])
    # print(b, d)
    dp = {}
    if b == 0 and d == 0:
        exit(0)

    #for i in range(0, d+1):
    #    print("aaa", i)
    #    dp[i][0] = -1
    #    dp[i][1] = -1
    print(f(d-1, 1) + (b-2)*f(d-1, 0))

    #except:
    #    exit(0)

