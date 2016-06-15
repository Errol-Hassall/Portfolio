#Project euler problem 5

def main():
	l_test = 2520
	l_continue = True
	l_number = 10
	l_check = 0
	while l_continue:
		for num in range (1, 21):
			if l_check == 19:
				l_continue = False
				print(l_number)
				break
			if l_number % num == 0:
				l_check += 1
			if l_number % num != 0:
				l_check = 0
				break
		if(l_continue == True):
			l_number += 10
	
main()
