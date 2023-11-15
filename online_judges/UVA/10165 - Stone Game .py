from decimal import Decimal, getcontext
import math, sys
input = sys.stdin.readline

# getcontext().prec = 3 # 3 de precision, trunca el resto.
# n = Decimal(1) / Decimal(3)


# try:
#    x = input() # until EOF.
# except:
#    exit(0)
# v = [k for k in map(int, s.split(' '))]

# map(int, input().split())

while True:
    x = int(input())
    if x == 0:
        break
    s = input()
    v = [k for k in map(int, s.split(' '))]
    u = 0
    for el in v:
        u ^= el
    if u == 0:
        print("No")
    else:
        print("Yes")

