# Program multiples of 3 and 5

def Multiples():
	l_total = 0
	x = 1
	for x in range(1,1000):
		if(x % 3 == 0 or x % 5 == 0):
			l_total += x	
	print(l_total)



Multiples()

