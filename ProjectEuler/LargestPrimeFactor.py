#Project Euler problem 3
import math

def slow():
	l_target_number = 600851475143
	l_example_num = 13195
	l_list_of_primes = []
	for num in range(2, l_example_num):
		l_list_of_primes.append(num)
		prime = 2
		while prime <= num - 1:
			if(num % prime == 0):
				l_list_of_primes.remove(num)
				break
			prime = prime + 1
		if l_example_num % num != 0 and num in l_list_of_primes:
			l_list_of_primes.remove(num)
	print(l_list_of_primes)	


def medium():
	l_target_number = 600851475143
	l_example = 13195
	l_list_of_factors = []
	for num in range(2, l_target_number):
		if l_target_number % num == 0:
			l_list_of_factors.append(num)
	print(l_list_of_factors)
	for factor in l_list_of_factors[::1]:
		prime = 2
		l_continue = True
		while prime <= factor-1 and l_continue == True:
			if(factor % prime == 0):
				l_list_of_factors.remove(factor)
				l_continue = False
			prime += 1
	print(l_list_of_factors)


def fast():
	l_target_number = 600851475143
	l_example = 13195
	l_list_of_factors = []
	l_remainder = l_target_number
	condition = True
	l_div = 2
	l_skip = False
	l_total = 1
	while condition:
		if(l_remainder % l_div == 0):
			l_remainder = l_remainder / l_div
			l_list_of_factors.append(l_div)
			l_total *= l_div
		elif l_skip == False:
			l_div += 1
			l_skip = True
		else:
			l_div += 2
		
		if l_total == l_target_number:
			condition = False
			print(l_list_of_factors)
			print(l_total)
				
	
fast()


