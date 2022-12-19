import sys
sys.stdin = open('input_10871', 'r')

n, x = map(int, input().split())
A = list(map(int, input().split()))


for i in A:
    if i < x:
        print(i, end=' ')




