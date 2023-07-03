# 붙임성 좋은 총총이
import sys
input = sys.stdin.readline

n = int(input())
dance = set()
dance.add('ChongChong')

for i in range(n):
    a, b = input().split()
    if a in dance:
        dance.add(b)
    elif b in dance:
        dance.add(a)

print(len(dance))
