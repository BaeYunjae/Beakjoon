# 인사성 밝은 곰곰이
import sys
input = sys.stdin.readline

n = int(input())
gomgom= set()
cnt = 0

for _ in range(n):
    word = input().strip()
    if word != 'ENTER' and word not in gomgom:
        cnt += 1
        gomgom.add(word)
    elif word == 'ENTER':
        gomgom.clear()

print(cnt)
