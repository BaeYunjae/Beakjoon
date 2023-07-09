# 균형잡힌 세상
while True:
    string = input()
    if string == '.': break

    stack = []
    IsCorrect = True
    for now in string:
        if now == '(' or now == '[':
            stack.append(now)
        elif now == ')':
            if not stack or stack[-1] == '[':
                IsCorrect = False
                break
            else:
                stack.pop()
        elif now == ']':
            if not stack or stack[-1] == '(':
                IsCorrect = False
                break
            else:
                stack.pop()

    if not stack and IsCorrect: print("yes")
    else: print("no")
