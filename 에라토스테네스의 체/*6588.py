# 골드바흐의 추측
import sys
input = sys.stdin.readline

prime_list = [1] * 1000001

for i in range(2, int(len(prime_list)**0.5) + 1):
    if prime_list[i]:
        for j in range(i + i, len(prime_list), i):
            prime_list[j] = 0

while True:
    n = int(input())
    if not n: break
    for i in range(3, n // 2 + 1, 2):
        if prime_list[i] and prime_list[n - i]:
            print(f"{n} = {i} + {n - i}")
            break
    else:
        print("Goldbach's conjecture is wrong.")
