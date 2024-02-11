S = input()
ans = 0
for i in range(10000):
    flag = [False]*10
    x = i
    for j in range(4):
        flag[x%10] = True
        x //= 10
    flag2 = True
    for j in range(10):
        if S[j] == 'o' and not flag[j]:
            flag2 = False
        if S[j] == 'x' and flag[j]:
            flag2 = False
    ans += flag2
print(ans)
