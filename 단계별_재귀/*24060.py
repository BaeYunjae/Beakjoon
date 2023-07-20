# 알고리즘 수업 - 병합 정렬 1
import sys

def merge_sort(A, p, r):         # 배열 A를 오름차순 정렬
    if p < r and cnt <= k:
        q = (p + r) // 2         # q는 p, r의 중간 지점
        merge_sort(A, p, q)      # 전반부 정렬
        merge_sort(A, q + 1, r)  # 후반부 정렬
        merge(A, p, q, r)        # 병합

# A[p...q]와 A[q+1...r]을 병합하여 A[p...r]을 오름차순 정렬된 상태로 만든다.
# A[p...q]와 A[q+1...r]은 이미 오름차순으로 정렬되어 있다.
def merge(A, p, q, r):
    global cnt, ans
    i = p
    j = q + 1
    tmp = []

    while i <= q and j <= r:
        if (A[i] <= A[j]):
            tmp.append(A[i])
            i += 1
        else:
            tmp.append(A[j])
            j += 1

    while i <= q:         # 왼쪽 배열 부분이 남은 경우
        tmp.append(A[i])
        i += 1 
    while j <= r:         # 오른쪽 배열 부분이 남은 경우
        tmp.append(A[j])
        j += 1

    i = p
    t = 0
    while i <= r:         # 결과를 A[p...r]에 저장
        A[i] = tmp[t]
        cnt += 1          # 저장할 때마다 카운트
        if cnt == k:      # 저장한 횟수가 k와 같으면 
            ans = A[i]    # 그 값을 ans에 저장
            break
        i += 1
        t += 1


n, k = map(int, input().split())  # 배열 A의 크기, 저장 횟수 k
A = list(map(int, sys.stdin.readline().split()))

cnt = 0
ans = -1
merge_sort(A, 0, n - 1)
print(ans)
