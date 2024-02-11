N = int(input())
list = []
for i in range(0, N):
    s, t = input().split()
    t = int(t)
    list.append([t, s])
list.sort()
print(list[-2][1])
