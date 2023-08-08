# 스도쿠
# 첫번째 풀이 (141600KB, 2880ms)
def possible(x, y, n):  # 행, 열, 숫자
    global sudoku
    # 행
    for i in range(9):
        if sudoku[x][i] == n:
            return False

    # 열
    for i in range(9):
        if sudoku[i][y] == n:
            return False

    # 사각형
    x0 = (x // 3) * 3  # 4행 4열, (x0, y0) = (3, 3)
    y0 = (y // 3) * 3
    for i in range(3):
        for j in range(3):
            if sudoku[x0+i][y0+j] == n:
                return False
    return True

def solve():
    global sudoku

    for x in range(9):
        for y in range(9):
            if sudoku[x][y] == 0:
                for n in range(1, 10):
                    if possible(x, y, n):
                        sudoku[x][y] = n
                        solve()  # 다음 빈 곳
                        sudoku[x][y] = 0
                return

    for i in range(9):
        print(*sudoku[i])
    exit()  # 강제종료 안하면 틀림

sudoku = [list(map(int, sys.stdin.readline().split())) for _ in range(9)]

solve()

---------------------------------------------------------------------------
# 두번째 풀이 (144636KB, 3268ms)
import sys

sudoku = [list(map(int, sys.stdin.readline().split())) for _ in range(9)]
blank = []

for i in range(9):
    for j in range(9):
        if sudoku[i][j] == 0:
            blank.append((i, j))

def row(x, n):
    for i in range(9):
        if sudoku[x][i] == n:
            return False
    return True

def col(y, n):
    for i in range(9):
        if sudoku[i][y] == n:
            return False
    return True

def square(x, y, n):   # 행, 열, 숫자
    x0 = (x // 3) * 3  # 3x3 사각형 시작점 좌표
    y0 = (y // 3) * 3
    for i in range(3):
        for j in range(3):
            if sudoku[x0+i][y0+j] == n:
                return False
    return True

def dfs(idx):
    if idx == len(blank):
        for i in range(9):
            print(*sudoku[i])
        exit()

    for n in range(1, 10):
        x = blank[idx][0]
        y = blank[idx][1]
        if row(x, n) and col(y, n) and square(x, y, n):
            sudoku[x][y] = n
            dfs(idx + 1)  # 다음 빈 곳
            sudoku[x][y] = 0

dfs(0)

