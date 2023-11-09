# 과제 안 내신 분..?
students = [i for i in range(1, 31)]

for _ in range(30):
    try:
        submit = int(input())
        students.remove(submit)
    except EOFError:
        break
    
print(min(students))
print(max(students))
