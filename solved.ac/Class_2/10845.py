# 첫번째 풀이 - 덱 (34160KB, 76ms)
import sys
input = sys.stdin.readline

n = int(input())
q = []
for _ in range(n):
    command = list(input().split())
    if command[0] == 'push':
        q.append(int(command[1]))
    if command[0] == 'front':
        if q:
            print(q[0])
        else:
            print(-1)
    if command[0] == 'back':
        if q:
            print(q[-1])
        else:
            print(-1)
    if command[0] == 'size':
        print(len(q))
    if command[0] == 'empty':
        if q:
            print(0)
        else:
            print(1)
    if command[0] == 'pop':
        if q:
            print(q.pop(0))
        else:
            print(-1)

--------------------------------------
# 두번째 풀이 - 리스트 (31256KB, 52ms) <--- 메모리 사용량이 덱보다 적고 더 빠르다
import sys
input = sys.stdin.readline

n = int(input())
q = []
for _ in range(n):
    command = list(input().split())
    if command[0] == 'push':
        q.append(int(command[1]))
    if command[0] == 'front':
        if q:
            print(q[0])
        else:
            print(-1)
    if command[0] == 'back':
        if q:
            print(q[-1])
        else:
            print(-1)
    if command[0] == 'size':
        print(len(q))
    if command[0] == 'empty':
        if q:
            print(0)
        else:
            print(1)
    if command[0] == 'pop':
        if q:
            print(q.pop(0))
        else:
            print(-1)
