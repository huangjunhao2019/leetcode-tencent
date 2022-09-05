def A(n,k):
    res=1
    for i in range(n-k+1,n+1):
        res*=i
    return res
def solve():
    tempN,tempP=input().split()
    n=int(tempN)
    p=float(tempP)
    newP=0.0
    k =1
    if n==1:
        print(k)
        return
    while newP<p:
        newP=1-A(n,k)/(n**k)
        if newP>=p:
            break
        k+=1
    print(k)
solve()