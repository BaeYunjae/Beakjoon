# 프린트 큐
# 첫번째 풀이 (34104KB,	80ms)
from collections import deque

T = int(input())

for _ in range(T):
    cnt = 0
    queue = deque()
    n, m = map(int, input().split())  # 문서의 개수, 궁금한 문서
    priority = list(map(int, input().split()))
    for i in range(n):
        queue.append((i, priority[i]))
    while True:
        if queue[0][1] < max(priority):
            queue.append(queue.popleft())
        if queue[0][1] == max(priority):
            if queue[0][0] == m:
                print(cnt + 1)
                break
            queue.popleft()
            cnt += 1
            priority.remove(max(priority))

-----------------------------------------------------------------------------------------------------
# 두번째 풀이 (31256KB, 68ms)
T = int(input())
arr = []
for _ in range(T):
    n, m = map(int, input().split())  # 문서 개수, 궁금한 문서 자리
    arr = list(enumerate(list(map(int, input().split()))))  # enumerate()은 인덱스와 원소의 튜플 생성
    target = arr[m]  # 궁금한 문서
    cnt = 0          # 프린트한 횟수
    while len(arr):
        max_value = max([i[1] for i in arr])  # 가장 높은 문서 중요도
        if arr[0][1] == max_value:            # 가장 높은 문서 중요도면
            now = arr.pop(0)                  # 프린트 (내보내기)
            cnt += 1
            if now == target:
                print(cnt)
                break
        else:
            now = arr.pop(0)                  # 가장 높은 문서 중요도가 아니면 뒤로
            arr.append(now)
          
