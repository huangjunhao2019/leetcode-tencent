from scipy.special import comb, perm

def chooseN(n,m):
    if n==0:
        return 1
    Anm=1
    Amm=1
    for i in range(1,m+1):
        Amm*=i
    for i in range(n-m+1,n+1):
        Anm*=i
    return Anm//Amm
    
def chooseEven(time):
    res=0
    mp=dict()
    for i in range(0,time+1,2):
        if time-i in mp:
            res+=mp[time-i]
        else:
            temp= comb(time,i)
            res+=temp
            mp[i]=temp
    return res
def main():
    temp = input()
  #  print(temp)
    n = len(temp)
    if n==0:
        print(0)
        return
    d=dict()
    for i in range(n):
        if temp[i] in d:
            d[temp[i]]+=1
        else:
            d[temp[i]]=1
    res=1 
   # print(d)
    for key,time in d.items():
        res*=chooseEven(time)
    res-=1 
    print(int(res)%int(1e9+7))
    return

if __name__ == "__main__":
    main()