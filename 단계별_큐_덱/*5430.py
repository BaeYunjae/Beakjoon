# AC
from collections import deque

t = int(input())

for _ in range(t):
    p = input()
    n = int(input())
    dq = deque(input()[1:-1].split(','))  # 입력 숫자 부분만 덱에 저장
    flag = 0      # R 횟수

    if n == 0:    # 수의 개수가 0이면
        dq = []  # 빈 리스트

    for i in p:         # 수행할 함수가
        if i == 'R':    # R 이면
            flag += 1   # R 횟수 증가
        elif i == 'D':  # D 면
            if len(dq) == 0:  # 덱이 비어있을 때
                print("error") # 에러
                break
            else:
                if flag % 2 == 0:  # R 횟수가 짝수면
                    dq.popleft()  # 첫번째 수 버리기
                else:              # 홀수면
                    dq.pop()      # 마지막 수 버리기
    else:
        if flag % 2 == 1:  # R이 홀수면
            dq.reverse()  # 덱 뒤집고
        print('[' + ','.join(dq) + ']')  # 리스트로 만들기
