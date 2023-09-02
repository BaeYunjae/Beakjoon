# ACM 호텔
import sys
input = sys.stdin.readline

T = int(input())
for _ in range(T):
    H, W, N = map(int, input().split())  # 층 수, 방 수, 몇 번째 손님
    if N % H == 0:
        print(H*100 + N // H)
    else:
        print((N % H) * 100 + (N // H + 1))
