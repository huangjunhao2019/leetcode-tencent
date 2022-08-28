modNum=10**9+7
n=input()
res =0
for i in range(2,n):
    if i+2>n-3:
        continue
    res+=(n-3)-(i+1)+1
temp=1
res =max(res,1)
res = res  % modNum
print(res)