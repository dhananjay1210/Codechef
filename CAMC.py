from collections import deque
t = int(input())
for _ in range(t):
	n,m = list(map(int,input().split()))
	arr = list(map(int,input().split()))
	i = 0
	mx_q, mn_q = deque(),deque()
	for i in range(m):
		while mx_q and arr[mx_q[-1]] <= arr[i]:
			mx_q.pop()
		while mn_q and arr[mn_q[-1]] >= arr[i]:
			mn_q.pop()
		mx_q.append(i)
		mn_q.append(i)
	ans = float('inf')
	for i in range(m,n):
		ans = min(ans,arr[mx_q[0]] - arr[mn_q[0]])
		while mx_q and mx_q[0] <= i-m:
			mx_q.popleft()
		while mn_q and mn_q[0] <= i-m:
			mn_q.popleft()
		
		while mx_q and arr[mx_q[-1]] <= arr[i]:
			mx_q.pop()
		while mn_q and arr[mn_q[-1]] >= arr[i]:
			mn_q.pop()
		mx_q.append(i)
		mn_q.append(i)
	
	print(ans)