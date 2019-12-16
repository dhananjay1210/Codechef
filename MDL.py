t = int(input())
for _ in range(t):
    n = int(input())
    arr = list(map(int,input().split()))
    mn,mnInd,mx,mxInd = 1000,-1,0,-1
    
    for i in range(n):
        if arr[i]<mn:
            mn = arr[i]
            mnInd = i
        if arr[i]>mx:
            mx = arr[i]
            mxInd = i
    if mnInd<mxInd:
        print(mn,mx)
    else:
        print(mx,mn)