# 나는야 포켓몬 마스터 이다솜
import sys
input = sys.stdin.readline

n, m = map(int, input().split())  # 포켓몬 수, 문제 수
pokemon = dict()

for i in range(1, n + 1):
    p = input().strip()
    pokemon[p] = i         # 이름: 번호
    pokemon[i] = p         # 번호: 이름

for _ in range(m):
    q = input().strip()
    if q.isdigit():
        print(pokemon[int(q)])  # 번호(키)면 이름(값)
    else:
        print(pokemon.get(q))   # 이름이면 번호(값)
