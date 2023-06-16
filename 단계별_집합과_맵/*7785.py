# 회사에 있는 사람 
import sys
input = sys.stdin.readline

n = int(input())
worker = dict()

for _ in range(n):
    name, log = input().split()
    if log == 'enter':
        worker[name] = log
    else:
        del worker[name]
        
worker = sorted(worker.keys(), reverse=True)

for name in worker:
    print(name)
