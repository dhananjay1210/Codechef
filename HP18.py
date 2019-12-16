def gcd(x, y):
	while(y):
		x, y = y, x % y
	return x

for t in range(int(input())):
	n,a,b = map(int,input().split())
	arr= map(int,input().split())
	gcd1 = gcd(a,b)
	lcm = (a*b)/gcd1
	
	bob=0
	alice=0
	cmn=0
	chance = 'BOB'
	for i in arr:
		if i%lcm==0:
			cmn +=1
		elif i%a==0:
			bob += 1
		elif i%b==0:
			alice += 1
	
	if bob > alice:
		print('BOB')
	if alice > bob:
		print('ALICE')
	if alice==bob:
		if cmn > 0:
			print('BOB')
		else:
			print('ALICE')