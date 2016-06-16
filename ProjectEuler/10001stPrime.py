#Problem 7 10,001st prime
import time

def main():
	l_iteration = 1
	l_list_of_primes = [2]
	l_check = True
	l_number = 3
	
	while l_check:
		prime_check = 2
		l_prime_continue = True
		while prime_check <= l_number -1 and l_prime_continue:
			if l_number % prime_check == 0:
				l_prime_continue = False
			prime_check += 1		
		if prime_check == l_number:
			l_list_of_primes.append(l_number)
			l_iteration += 1
		if l_iteration == 10001:
			print(l_list_of_primes)
			l_check = False
			break
		l_number += 2

main()
