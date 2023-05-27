# 알고리즘 수업 - 알고리즘의 수행 시간 4
# MenOfPassion 알고리즘
# MenOfPassion(A[], n) {
#     sum <- 0;
#     for i <- 1 to n - 1
#         for j <- i + 1 to n
#             sum <- sum + A[i] × A[j]; # 코드1
#     return sum;
# }
n = int(input())
print(int(n*(n-1)/2))
print(2)
