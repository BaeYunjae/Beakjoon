# 스택 수열
import sys
input = sys.stdin.readline

n = int(input())
sequence = [int(input()) for _ in range(1, n + 1)]

stack = []
num = 1
IsCorrect = True
answer = ""

for i in range(n):
    now = sequence[i]
    if now >= num:
        while now >= num:
            stack.append(num)
            answer += "+\n"
            num += 1
        stack.pop()
        answer += "-\n"
    else:
        top = stack.pop()
        if top > now:
            print("NO")
            IsCorrect = False
            break
        else:
            answer += "-\n"

if IsCorrect:
    print(answer)
