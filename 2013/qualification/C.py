S = set()
S.add(9)

def backtrack(k, s, n):
    if s>=7: return
    if k==27:
        #print n
        nn = int(str(n) + str(n)[::-1])**2
        if str(nn) == str(nn)[::-1]:
            S.add(nn)
        nn = int(str(n) + str(n)[::-1][1:])**2
        if str(nn) == str(nn)[::-1]:
            S.add(nn)
        return        
    for i in range(3):
       backtrack(k+1, s+i, n*10+i)

backtrack(0, 0, 0)

S = sorted(list(S))

cases = int(raw_input())
for i in range(cases):
    a, b = map(int, raw_input().split())

    count = 0
    for x in S:
        if a<=x<=b:
            count+=1

    print "Case #{}: {}".format(i+1, count)
