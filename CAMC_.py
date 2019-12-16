t = int(input())
for _ in range(t):
	n,m = list(map(int,input().split()))
	ar = list(map(int,input().split()))
	col = 0
	arr = []
	for i in range(n):
		arr.append([ar[i],col%m])
		col += 1
	arr.sort(key = lambda x:x[0])
	
	dic = {}
	i = j = 0
	ans = float('inf')
	while j < n:
		dic[arr[j][1]] = dic.get(arr[j][1],0) + 1
		while dic and dic[arr[i][1]] > 1:
			dic[arr[i][1]] -= 1
			i += 1
		if len(dic) == m:
			ans = min(ans,arr[j][0]-arr[i][0])
			#print(i,j,ans)
		#print(j,dic)
		j+=1
	print(ans)