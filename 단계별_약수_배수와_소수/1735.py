# 분수 합
# 첫번째 풀이 (52ms)
def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

a1, b1 = map(int, input().split())
a2, b2 = map(int, input().split())

deno = b1 * b2 / gcd(b1, b2)
nume = a1 * (deno / b1) + a2 * (deno / b2)

GCD = gcd(nume, deno)

print(int(nume / GCD), int(deno / GCD))

-----------------------------------------------
# 두번째 풀이 (40ms)
def gcd(a, b):
    if b == 0:
        return a
    else:
        return gcd(b, a % b)

a1, b1 = map(int, input().split())
a2, b2 = map(int, input().split())

nume = a1 * b2 + a2 * b1
deno = b1 * b2

GCD = gcd(nume, deno)

print(nume // GCD, deno // GCD)
 
