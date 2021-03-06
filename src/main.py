# Permutation 1-D Array
from numpy import random

def build_array(size):
	arr = []
	is_auto = input("auto fill?: [y/n] ")
	while(True):
		if is_auto == 'y':
			for inp in range(size):
				arr.append(inp)
			return arr
			break
		elif is_auto == 'n':
			for i in range(size):
				input_element = int(input("arr[" + str(i) + "]: "))
				arr.append(input_element)
			return arr
			break
		else:
			print("select 'y' / 'n'")

def sum_inv(arr):
	num_inv = 0
	for i in range(len(arr)):
		for j in range(i, len(arr)):
			if arr[i] > arr[j]:
				num_inv += 1
	return num_inv

def factorial(num):
	return 1 if (num==0 or num==1) else num * factorial(num-1)

def even_parameter(num):
	return num % 2 == 0

# DRIVER CODE
print("permutation 1-D array")
size = int(input("size: "))
arr = build_array(size)
print("your array: ",arr,"\n")

# build n permutation
print("==== Permutation ====")
permutation_loop = factorial(size)
for i in range(permutation_loop):
	rp = random.permutation(arr)
	num_inv = sum_inv(rp) # determine number of invers in of each permutation arrays
	is_even = even_parameter(num_inv)

	# determine label wether odd or even
	if is_even:
		print(rp, "Jumlah invers = ", num_inv, "(even permutation)")
	else:
		print(rp, "Jumlah invers = ", num_inv, "(odd permutation)")

print("there is", permutation_loop , "loops of permutation")



