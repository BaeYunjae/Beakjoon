# 인간-컴퓨터 상호작용 (서브테스크)
# 50점
import sys
input = sys.stdin.readline

S = list(input())  # 문자열
n = int(input())   # 질문 개수

for i in range(n):
    q = list(input().split())
    a = q[0]
    start = int(q[1])
    end = int(q[2])
    if a in S[start:end + 1]:
        print(S[start:end + 1].count(a))
    else:
        print(0)
      
--------------------------------------------------------------------------------
# 100점
# 첫번째 풀이 PyPy3 (168012KB, 440ms)
import sys
input = sys.stdin.readline

S = list(input().strip())    
n = int(input().strip())     
s_list = [[0] * len(S) for _ in range(26)]

for i in range(1, len(S)):
    s_list[ord(S[i])-ord('a')][i] += 1

for i in range(26):
    for j in range(1, len(S)):
        s_list[i][j] += s_list[i][j-1]

for i in range(n):
    a, l, r = input().split()
    tmp = s_list[ord(a)-ord('a')][int(r)] - s_list[ord(a)-ord('a')][int(l)]

    if S[int(l)] == a:
        tmp += 1

    print(tmp)

--------------------------------------------------------------------------------
# 두번째 풀이 PyPy3 (184424KB, 588ms)
import sys
input = sys.stdin.readline

S = list(input())    # 문자열
n = int(input())     # 질문 개수
# print(ord('a'))    # 97
# print(ord('z'))    # 122
# a~z의 알파벳 개수는 26개
s_list = [[0] * 26 for _ in range(len(S) + 1)]  # 가로(행): 문자열, 세로(열): 알파벳

for i in range(1, len(S) + 1):     # i = 7이면
    for j in range(26):            # a ~ z
        if ord(S[i-1]) - 97 == j:  # S[7-1] = S[6] = 'a', ord('a') = 97, 97 - 97 = 0
            s_list[i][j] = s_list[i-1][j] + 1  # s_list[7][0] = s_list[6][0] + 1 => 1
        else:
            s_list[i][j] = s_list[i-1][j]      # 'a'가 아닌 다른 자리는 이전 값 가져옴

for _ in range(n):
    a, l, r = input().split()
    a, l, r = ord(a) - 97, int(l), int(r)
    print(s_list[r + 1][a] - s_list[l][a])
  
