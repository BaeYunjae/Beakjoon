# 너의 평점은
score = {'A+': 4.5, 'A0': 4.0, 'B+': 3.5, 'B0': 3.0, 'C+': 2.5,
        'C0': 2.0, 'D+': 1.5, 'D0': 1.0, 'F': 0.0}
scoreSum = 0
creditSum = 0 

for _ in range(20):
    subject, credit, grade = map(str, input().split())
    if grade != 'P':
        creditSum += float(credit)
    for key, value in score.items():
        if key == grade:
            scoreSum += (float(credit) * value)
            
print(format(scoreSum / creditSum, ".6f"))
