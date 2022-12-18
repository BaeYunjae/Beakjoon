import sys
sys.stdin = open('input_10807', 'r')

N = input()
num = list(map(int, input().split()))
v = int(input())
sum = 0

for i in num:
    if i == v:
        sum += 1

print(sum)
