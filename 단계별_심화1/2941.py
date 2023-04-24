# 크로아티아 알파벳
# 첫번째 풀이
change = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']
alphabet = input()
cnt = 0

for c in change:
    if c in alphabet:
        cnt += alphabet.count(c)
        alphabet = alphabet.replace(c, ' ')
        
print(cnt + len(alphabet.replace(' ', '')))

-----------------------------------------------------------

# 두번째 풀이
change = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']
alphabet = input()

for c in change:
    alphabet = alphabet.replace(c, '*')
    
print(len(alphabet))
