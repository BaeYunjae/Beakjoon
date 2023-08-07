# queuestack
from collections import deque

n = int(input())
check = list(map(int, input().split()))
components = list(map(int, input().split()))
m = int(input())
insert = list(map(int, input().split()))

# 스택은 무시, 큐만 덱에 추가
q = deque()
for i in range(n):
    if check[i] == 0:
        q.append(components[i])                          # q.appendleft(components[i])                       
        print(q)

# 큐가 없으면 주어진 원소들 그대로 출력됨
if q == []:
    print(*insert)

# 덱이 하나의 큐처럼 작동
for i in range(m):
    q.appendleft(insert[i])  # 원소가 삽입되는 위치와    # q.append(insert[i])
    print(q.pop(), end=" ")  # 빼내는 위치가 반대면 됨   # print(q.popleft(), end=" ")
