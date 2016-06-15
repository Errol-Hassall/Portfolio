#Project Euler Problem 4

def main():
	l_continue = True
	l_left = 999
	l_right = 999
	l_palindrome = 0
	l_right_decrement = True
	l_left_decrement = False
	l_highest = 0
	while l_continue:
		l_palindrome = l_right * l_left
		l_palindrome = str(l_palindrome)
		l_reverse = l_palindrome
		l_reverse = l_reverse[::-1]
		if (l_reverse == l_palindrome and int(l_reverse) > l_highest):
			l_highest = int(l_reverse)		
			
		if (l_right >= 900):
			l_right -= 1
			if(l_right <= 900):
				l_left_decrement = True
			
		if (l_left_decrement == True):
			l_left -= 1
			l_left_decrement = False
			l_right = 999
			
		if(l_left <=900):
				print(l_highest)
				l_continue =False
	
main()
