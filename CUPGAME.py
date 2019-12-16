T = int(input())

while(T):
	n,k = map(int,input().split())

	rem = n % 4
	finish = 0
	startby = ''

	if(rem == 0):
		finish = n
	else:
		finish = n - (4 - rem)

	finish = finish + k - 1
	if(finish > n):
		finish -= n
	
	#finish = finish - ((n//4) - 1)*4	
	if(n%2 == 0):
		startby = "L"
	else:
		startby = "Light"
		
	print(finish," ",startby)
	T -= 1