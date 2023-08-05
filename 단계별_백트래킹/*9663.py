# N-Queen 
# 첫번째 풀이 (124724KB, 11172ms)
def backtrack(r):
    global res
    if r == n:
        res += 1
        return

    for c in range(n):
        if c in col or (r + c) in posDiag or (r - c) in negDiag:
            continue

        col.add(c)
        posDiag.add(r + c)
        negDiag.add(r - c)

        backtrack(r + 1)  # 다음 행

        # 다음 경우의 수를 위해 모두 삭제
        col.remove(c)
        posDiag.remove(r + c)
        negDiag.remove(r - c)


n = int(input())
col = set()
posDiag = set()  # (r + c)
negDiag = set()  # (r - c)

res = 0

backtrack(0)
print(res)

----------------------------------------------------------------
# 두번째 풀이 (204932KB, 30128ms)
def promising(r):
    for i in range(r):
        if row[r] == row[i] or abs(row[r] - row[i]) == abs(r - i):
            return False
    return True

def backtrack(r):
    global res
    if r == n:
        res += 1
        return

    for c in range(n):
        # [r, c]에 퀸을 놓겠다
        row[r] = c
        if promising(r):
            backtrack(r + 1)  # 다음 행


n = int(input())

res = 0
row = [0] * n

backtrack(0)
print(res)
