# 괄호
import sys
input = sys.stdin.readline

n = int(input())

for _ in range(n):
    bracket = input()
    stack = [0] * len(bracket)
    top = -1
    IsCorrect = True
    for now in range(len(bracket)):
        if bracket[now] == '(':
            top += 1
            stack[top] = bracket[now]
        elif bracket[now] == ')':
            if stack[top] == '(':
                top -= 1
            elif top == -1:
                IsCorrect = False
                break
    if top == -1 and IsCorrect: print("YES")
    else: print("NO")
