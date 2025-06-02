from collections import Counter
from sys import stdin

input=lambda:stdin.readline()
ri=lambda:int(input())
rl=lambda:list(map(int,input().split()))

T=ri()
for _ in range(T):
    n=ri()
    s=input()
    cnt=Counter(s)
    if cnt[s[0]]==n:
        print(1)
        continue
    sl=1
    while sl<n and s[sl]==s[0]:
        sl+=1
    if sl==cnt[s[0]]:
        print(1+min(3,n-sl))
    else:
        print(2)
