t = int(input())
vow = ['a','e','i','o','u']

def expo(x,y):
	if y==1:
		return x
	res = expo(x,y//2)
	if y%2:
		return res*res*x
	else:
		return res*res

for _ in range(t):
	l = int(input())
	a_total,b_total,a_doc,b_doc = {},{},{},{}
	a,b = 0,0 
	for i in range(l):
		s = input().strip()
		alice = 1
		for j in range(1,len(s)):
			v,c = 0,0
			for k in range(3):
				if j-k >= 0:
					if s[j-k] in vow:
						v += 1
					else:
						c += 1
			if v<c:
				alice = 0
				break
		
		hs = [1]*27
		for j in range(len(s)):
			if alice:
				a_total[s[j]] = a_total.get(s[j],0) + 1
				if hs[ord(s[j]) - 97]:
					hs[ord(s[j]) - 97] = 0
					a_doc[s[j]] = a_doc.get(s[j],0) + 1
			else:
				b_total[s[j]] = b_total.get(s[j],0) + 1
				if hs[ord(s[j]) - 97]:
					hs[ord(s[j]) - 97] = 0
					b_doc[s[j]] = b_doc.get(s[j],0) + 1
		if alice:
			a+=1
		else:
			b+=1

	l1,l2 = [],[]
				
	for i in a_doc:
		l1.append(a_doc[i])
		l2.append((a_total[i]**a))
	for i in b_doc:
		l2.append(b_doc[i])
		l1.append((b_total[i]**b))
	l1.sort()
	l2.sort()
	
	i,j = 0,0
	sc = 1
	while i<len(l1) and j<len(l2):
		while i<len(l1) and sc <= 1:
			sc *= l1[i]
			i += 1
		while j<len(l2) and sc > 1:
			sc /= l2[j]
			j += 1
	while i<len(l1):
		sc *= l1[i]
		i += 1
	while j<len(l2):
		sc /= l2[j]
		j += 1

	score = sc
	if score > 10000000:
		print('Infinity')
	else:
		print(score)