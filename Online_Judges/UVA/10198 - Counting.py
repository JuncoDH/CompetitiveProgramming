from decimal import Decimal, getcontext
import math, sys
input = sys.stdin.readline

# getcontext().prec = 3 # 3 de precision, trunca el resto.
# n = Decimal(1) / Decimal(3)

# try:
#    x = input() # until EOF.
#    if len(x) == 0:
#        break
# except:
#    exit(0)
# v = [k for k in map(int, s.split(' '))]

# map(int, input().split())

MAX = 1005
dp = MAX*[-1]
def f(num):
    if num == 0:
        return 1
    if num < 0:
        return 0
    if dp[num] != -1:
        return dp[num]
    dp[num] = 2*f(num-1) + f(num-2) + f(num-3)
    return dp[num]

while True:
    try:
        x = input() # until EOF.
        if len(x) == 0:
            break
    except:
        exit(0)
    x = int(x)
    print(f(x))


