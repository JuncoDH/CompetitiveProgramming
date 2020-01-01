import math



def f(v, ma):
    i = ma
    s = sum(v)
    if s == n:
        num = math.factorial(n)
        for el in v:
            #print("before", num)
            num = num // math.factorial(el)
            #num = int(num + eps)
            #print("after", num)
        #se.add(int(num + eps))
        se.add(num)
        #print(v, round(num), num)
        return
    while i >= 0:
        if(i + 1 < d and v[i] == v[i + 1]):
            if i > 0:
                f(v, i-1)
            break
        v[i] += 1
        f(v, i)
        v[i] -= 1
        i -= 1

#h = 5
#d = 3

eps = 1e-5

while True:
    d, h = [int(k) for k in input().split()]
    #d, h = 7, 5
    n = h - 1

    v = []
    for i in range(d):
        v.append(0)

    se = set()
    f(v, d - 1)
    for el in sorted(se):
        print(el)
    
