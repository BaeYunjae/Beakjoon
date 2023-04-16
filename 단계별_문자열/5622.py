# 다이얼
dial = ['ABC', 'DEF', 'GHI', 'JKL', 'MNO', 'PQRS', 'TUV', 'WXYZ']
nums = list(input())

for i in nums:
    for j in dial:
        if i in j:
             nums[nums.index(i)] = dial.index(j) + 2
                
print(sum(nums) + len(nums)) 
