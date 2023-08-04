# 도키도키 간식드리미
n = int(input())
students = list(map(int, input().split()))
wait = []
num = 1

while students:
    if students[0] == num:
        num += 1
        students.pop(0)
    else:
        wait.append(students.pop(0))

    while wait:
        if wait[-1] == num:
            wait.pop()
            num += 1
        else:
            break

if not wait: print("Nice")
else: print("Sad")
