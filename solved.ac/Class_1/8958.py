# OX퀴즈
import sys

n = int(sys.stdin.readline())

for _ in range(n):
    sum = 0
    cnt = 0
    res = input()
    for i in range(len(res)):
        if res[i] == 'O':
            cnt += 1
        else:
            cnt = 0
        sum += cnt

    print(sum)
