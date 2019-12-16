t = int(input())

for _ in range(t):
	l,r = map(int,input().split())
	res = []
	
	r = list(bin(r)[2:])
	l = list(bin(l)[2:])
	l = ['0']*(len(r)-len(l)) + l
	flag = 0
	for i in range(len(l)):
		if r[i]==l[i]:
			res.append(l[i])
		else:
			flag = 1
			break
	if flag:
		for j in range(i,len(l)):
			res.append('1')
	
	print(int("".join(res),2))