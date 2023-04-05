# 오븐 시계
start_h, start_m = map(int, input().split())
cook_time = int(input())

cook_h = cook_time // 60
cook_m = cook_time % 60

end_h = start_h + cook_h
end_m = start_m + cook_m

if end_m >= 60:
    end_m -= 60
    end_h +=1
if end_h >= 24:
    end_h -= 24
    
print(end_h, end_m)
