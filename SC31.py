t = int(input())
for _ in range(t):
	n = int(input())
	ans = [0,0,0,0,0,0,0,0,0,0]
	for i in range(n):
		temp = list(input())
		for j in range(len(temp)):
			ans[j] = ans[j] ^ int(temp[j])
	print(ans.count(1))