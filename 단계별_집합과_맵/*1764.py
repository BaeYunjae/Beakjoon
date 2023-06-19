# 듣보잡
# sys.stdin.readline()은 input()뒤에 개행문자를 넣는다. ex) 3 -> 3\n

# 첫번째 풀이 (44932KB, 76ms)
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
no_listen = [input() for _ in range(n)]
no_see = [input() for _ in range(m)]

result = sorted(list(set(no_listen) & set(no_see)))

print(len(result))
print(''.join(result), end='')

# 출력 
# 2
# baesangwookohhenrie 지만 개행문자가 붙어있는 것이므로 정답

-------------------------------------------------------------

# 두번째 풀이 (44060KB,	3736ms)
n, m = map(int, input().split())
no_listen = set()
no_see = set()

for _ in range(n):
    no_listen.add(input())
for _ in range(m):
    no_see.add(input())

result = sorted(list(no_listen & no_see))
print(len(result))

for name in result:
    print(name)
   
# 출력
# 2
# baesangwook
# ohhenrie
    
-------------------------------------------------------------

# 세번째 풀이 (44060KB, 92ms)
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
no_listen = set()
no_see = set()

for _ in range(n):
    no_listen.add(input().strip())  # 개행문자 제거
for _ in range(m):
    no_see.add(input().strip())     # 개행문자 제

result = sorted(list(no_listen & no_see))
print(len(result))

for name in result:
    print(name)
    
# 출력
# 2
# baesangwook
# ohhenrie

--------------------------------------------------------------

# 오답
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
no_listen = [input() for _ in range(n)]
no_see = [input() for _ in range(m)]

result = sorted(list(set(no_listen) & set(no_see)))

print(len(result))
for name in result:
    print(name)
    
# 출력
# 2
# baesangwook
#
# ohhenrie

