# 알고리즘 수업 - 알고리즘의 수행 시간 5
# MenOfPassion 알고리즘
# MenOfPassion(A[], n) {
#     sum <- 0;
#     for i <- 1 to n
#         for j <- 1 to n
#             for k <- 1 to n
#                 sum <- sum + A[i] × A[j] × A[k]; # 코드1
#     return sum;
# }
n = int(input())
print(n*n*n)
print(3)
