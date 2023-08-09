# 연산자 끼워넣기
# 첫번째 풀이
n = int(input())
nums = list(map(int, input().split()))
op = list(map(int, input().split()))  # +, -, *, //

# 1e9는 무한(INF)의 값
max_value = -1e9  # -10억보다 크거나 같고
min_value = 1e9   # 10억보다 작거나 같다

def backtrack(depth, total, add, sub, mul, div):
    global max_value, min_value
    if depth == n:
        max_value = max(total, max_value)
        min_value = min(total, min_value)

    if add:
        backtrack(depth + 1, total + nums[depth], add - 1, sub, mul, div)
    if sub:
        backtrack(depth + 1, total - nums[depth], add, sub - 1, mul, div)
    if mul:
        backtrack(depth + 1, total * nums[depth], add, sub, mul - 1, div)
    if div:
        backtrack(depth + 1, int(total / nums[depth]), add, sub, mul, div - 1)


backtrack(1, nums[0], op[0], op[1], op[2], op[3])

print(max_value)
print(min_value)

-------------------------------------------------------------------------------
# 두번째 풀이
n = int(input())
nums = list(map(int, input().split()))
add, sub, mul, div = map(int, input().split())  # +, -, *, //

# 1e9는 무한(INF)의 값
max_value = -1e9  # -10억보다 크거나 같고
min_value = 1e9   # 10억보다 작거나 같다

def backtrack(depth, total):
    global add, sub, mul, div, max_value, min_value
    if depth == n:
        max_value = max(total, max_value)
        min_value = min(total, min_value)

    if add:
        add -= 1  # 연산할 것 1개 빼주고
        backtrack(depth + 1, total + nums[depth])
        add += 1  # 모두 완료하면 다시 돌려줌
    if sub:
        sub -= 1
        backtrack(depth + 1, total - nums[depth])
        sub += 1
    if mul:
        mul -= 1
        backtrack(depth + 1, total * nums[depth])
        mul += 1
    if div:
        div -= 1
        backtrack(depth + 1, int(total / nums[depth]))
        div += 1


backtrack(1, nums[0])

print(max_value)
print(min_value)
