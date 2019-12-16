t = int(input())

def msb(N) :  
    msb_p = -1
    while (N) : 
        N = N >> 1 
        msb_p += 1 
    return msb_p

for _ in range(t):
	l,r = map(int,input().split())
	res = 0
	l_msb,r_msb = msb(l),msb(r)
	if r_msb==-1:
		print(0)
		continue
	while l_msb==r_msb and r_msb!=-1:
		inc = (1<<l_msb)
		res += inc
		l -= inc
		r -= inc
		l_msb,r_msb = msb(l),msb(r)
	if r_msb!=-1:
		temp = 1
		for j in range(r_msb):
			temp = (temp<<1)
			temp += 1
		res += temp
	print(res)