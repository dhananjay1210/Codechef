t = int(input())
d = {0:[0]}
arr = [0]
for i in range(1,129):
	ele = arr[-1]
	occ = d[ele]
	if len(occ)==1:
		arr.append(0)
		d[0].append(i)
	else:
		new = occ[-1] - occ[-2]
		arr.append(new)
		if new in d:
			d[new].append(i)
		else:
			d[new] = [i]
for _ in range(t):
	ind = int(input())
	ele = arr[ind-1]
	cnt = 0
	for j in d[ele]:
		if j!= (ind-1):
			cnt += 1
		else:
			break
	print(cnt+1)