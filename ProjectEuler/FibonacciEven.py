#Project Euler problem 2 Fibonacci sequence

def main():
	l_Previous = 1
	l_Current = 2
	l_Iteration = 1
	l_Total = 0
	l_Loop = True
	while l_Current < 4000000:
		l_Temp = l_Previous
		l_Previous = l_Current
		
		if(l_Current % 2 == 0):
			l_Total += l_Current
			print(l_Total)
		l_Current = l_Temp + l_Previous
			
		

main()
			 
