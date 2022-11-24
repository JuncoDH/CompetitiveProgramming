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
    try:
        n = input() # until EOF.
        p = input()
        n = int(n)
        p = int(p)
    except:
        exit(0)

    print(round(p**(1.0/n)))
