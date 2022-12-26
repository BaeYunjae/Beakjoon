import sys
sys.stdin = open('input_10866', 'r')

from collections import deque

N = int(input())
mydeque = deque()

for i in range(N):
    command = input().split()

    if command[0] == 'push_front':
        mydeque.appendleft(command[1])
    elif command[0] == 'push_back':
        mydeque.append(command[1])
    elif command[0] == 'pop_front':
        if mydeque:
            print(mydeque[0])
            mydeque.popleft()
        else:
            print(-1)
    elif command[0] == 'pop_back':
        if mydeque:
            print(mydeque[-1])
            mydeque.pop()
        else:
            print(-1)
    elif command[0] == 'size':
        print(len(mydeque))
    elif command[0] == 'empty':
        if mydeque:
            print(0)
        else:
            print(1)
    elif command[0] == 'front':
        if mydeque:
            print(mydeque[0])
        else:
            print(-1)
    elif command[0] == 'back':
        if mydeque:
            print(mydeque[-1])
        else:
            print(-1)
