# 파도반 수열
def padovan(n):
    for i in range(3, n + 1):
        p[i] = p[i - 3] + p[i - 2]
    return p[n]

T = int(input())
for _ in range(T):
    n = int(input())
    p = [1] * (n + 1)
    print(padovan(n - 1))  # p는 0부터 시작, 6번째 숫자는 5번 인덱스
