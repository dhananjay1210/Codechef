t = int(input())

def solve(curr,target):
	if curr==target:
		return 1
	if curr > target:
		return 0
	return solve(curr*10,target) or solve(curr*20,target)

for _ in range(t):
	n = int(input())
	if solve(1,n):
		print("Yes")
	else:
		print("No")
