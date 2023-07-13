# 회전하는 큐
# 첫번째 풀이
from collections import deque

n, m = map(int, input().split())
dq = deque([i for i in range(1, n + 1)])
find = list(map(int, input().split()))
num = 0
cnt = 0

for i in range(len(dq)):
    while num < m:                                   # num이 찾는 수의 개수보다 커지면 break
        if dq[i] != find[num]:
            if dq.index(find[num]) < len(dq) * 0.5:  # 찾는 수의 자리가 중앙값보다 앞에 있을 때
                dq.append(dq.popleft())              # 앞의 값을 뒤로 이동
                cnt += 1
            else:                                    # 반대로 중앙값보다 뒤에 있을 때
                dq.appendleft(dq.pop())              # 뒤의 값을 앞으로 이동
                cnt += 1
        else:
            dq.popleft()                             # 찾는 수를 빼내면
            num += 1                                 # num 값 증가
print(cnt)

----------------------------------------------------
# 두번째 풀이
from collections import deque

n, m = map(int, input().split())
dq = deque([i for i in range(1, n + 1)])
find = list(map(int, input().split()))
cnt = 0

for num in find:
    while True:
        if dq[0] == num:
            dq.popleft()
            break
        else:
            if dq.index(num) <= len(dq) / 2:
                dq.rotate(-1)  # 왼쪽회전
                cnt += 1
            else:
                dq.rotate(1)   # 오른쪽회전
                cnt += 1
print(cnt)
