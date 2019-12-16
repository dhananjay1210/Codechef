for t in range(int(input())):
	sent = input()
	flag=0
	for wrd in sent.split():
		if (wrd=='not' or wrd.find('n\'t')!= -1):
			print('Real Fancy')
			flag=1
			break
	if flag!=1:
		print('regularly fancy')