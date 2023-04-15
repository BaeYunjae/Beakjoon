# 알파벳 찾기
alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
            'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

S = input()
answer = [-1] * len(alphabet)

for i in range(len(S)):                      
    for j in range(len(alphabet)):               
        if S[i] == alphabet[j]:
            answer[j] = S.index(S[i])
            
for ans in answer:
    print(ans, end=' ')
    
    
-----------------------------------------------------------------------------


alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 
            'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

S = input()
answer = [-1] * len(alphabet)

for i in S:
    for j in alphabet:
        if i == j:
            answer[alphabet.index(j)] = S.index(i)
            
for ans in answer:
    print(ans, end=' ')
    
