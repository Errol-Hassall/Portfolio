#Sum of the Squares Problem 6 Project Euler

def main():
	l_sum_squares = 0
	l_square_sum = 0
	for num in range(1, 101):
		l_sum_squares += num ** 2
		print(l_sum_squares)
	print("This is the square of the sum")
	for num in range(1, 101):
		l_square_sum += num
	print(l_square_sum)
	l_square_sum = l_square_sum ** 2
	print(l_square_sum)
	
	l_dif = l_square_sum - l_sum_squares
	print(l_dif)

main()
