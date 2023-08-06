# 풍선 터뜨리기
from collections import deque

n = int(input())  # 풍선의 개수
balloon = deque(enumerate(map(int, input().split())))
# deque([(0, 3), (1, 2), (2, 1), (3, -3), (4, -1)])
ans = []

while balloon:
    idx, paper = balloon.popleft()
    ans.append(idx + 1)

    # rotate(-1): 원형 큐 반시계방향으로 1칸 회전
    # rotate(1): 원형 큐 시계방향으로 1칸 회전
    if paper > 0:    # 왼쪽 원소를 오른쪽에 삽입, 반시계방향
        balloon.rotate(-(paper - 1))
    elif paper < 0:  # 오른쪽 원소를 왼쪽에 삽입, 시계방향
        balloon.rotate(-paper)

print(' '.join(map(str, ans)))
