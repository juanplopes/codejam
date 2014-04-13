from math import floor

f = lambda n, r: 4*(n*n-n)/2 + (2*r+1)*n

cases = int(raw_input())
for case in range(cases):
    r, t = map(int, raw_input().split())

    begin, end = 0, 1e20
    
    while begin+1 < end:
        mid = (begin+end)/2
        x = f(mid, r)
        if x>t:
            end = mid
        else:
            begin = mid

    begin = int(floor(begin))
    while f(begin+1, r) <= t:
        begin += 1

    print "Case #{}: {}".format(case+1, begin)

