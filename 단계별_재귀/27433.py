# 팩토리얼 2
def factorial(a):
    if a > 1:
        return a * factorial(a - 1)
    return 1

print(factorial(int(input())))
