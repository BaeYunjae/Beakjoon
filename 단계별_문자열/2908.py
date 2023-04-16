# 상수
# 첫번째 풀이 (44ms)
x, y = map(int, input().split())
a = ''.join([i for i in reversed(str(x))])
b = ''.join([j for j in reversed(str(y))])

nums = []
nums.append(a)
nums.append(b)
print(max(nums))

-------------------------------------------

# 두번째 풀이 (40ms)
n1, n2 = input().split()
n1 = int(n1[::-1])
n2 = int(n2[::-1])

print(n1) if n1 > n2 else print(n2)
