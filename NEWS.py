T = int(input())
while(T):
	n,v1,v2= map(int,input().split())
	str1 = input()
	speed = v1
	x=0
	y=0
	
	for temp in str1:
		if(temp == '*'):
			if(speed == v1):
				speed = v2
			else:
				speed = v1
		else:
			if(temp == 'N'):
				y += speed
			
			elif(temp == 'S'):
				y -= speed
			
			elif(temp == 'E'):
				x += speed
			
			elif(temp == 'W'):
				x -= speed
			
	if(x<0):
		x *= -1
	if(y<0):
		y *= -1
	
	
	if(x%2 == 0):
		op = 'B'
		if(y > x):
			y = y-x
			if(y%2!=0):
				op = 'W'

	else:
		op = 'W'
		if(y > x):
			y = y-x
			if(y%2!=0):
				op = 'B'

	print(op)
	T = T -1
