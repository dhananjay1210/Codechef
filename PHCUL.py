import math
t = int(input())

def mn(x,y,l1,l2,l3):
	dist = float('inf')
	for i in range(0,len(l1),2):
		p1_x,p1_y = l1[i],l1[i+1]
		d1 = math.sqrt((p1_x-x)**2 + (p1_y-y)**2)
		if d1 < dist:
			for j in range(0,len(l2),2):
				p2_x,p2_y = l2[j],l2[j+1]
				d2= math.sqrt((p1_x-p2_x)**2 + (p1_y-p2_y)**2)
				if d1+d2 < dist:
					for q in range(0,len(l3),2):
						p3_x,p3_y = l3[q],l3[q+1]
						d3= math.sqrt((p3_x-p2_x)**2 + (p3_y-p2_y)**2)
						if d1+d2+d3 < dist:
							#print("p1 : ",p1_x,p1_y)
							#print("p2 : ",p2_x,p2_y)
							#print("p3 : ",p3_x,p3_y)
							dist = d1+d2+d3
							#print(dist)
	
	return dist
for _ in range(t):
	x,y = list(map(int,input().split()))
	n,m,k = list(map(int,input().split()))
	arr_n = list(map(int,input().split()))
	arr_m = list(map(int,input().split()))
	arr_k = list(map(int,input().split()))
	ans = mn(x,y,arr_n,arr_m,arr_k)
	ans = min(ans, mn(x,y,arr_m,arr_n,arr_k))
	print(ans)