def print_fibonacci(n):
  first = 0
  second = 1
  for i in range(0,n):
    if i <= 1:
      print(i,end = ", ")
    else:
      temp = first
      first = second
      second = temp + second
      print(second,end=", ")
# n = int(input("Enter N: "))
# print_fibonacci(n)

def find_factorial(n) -> int:
  factorial = 1
  for i in range(2,n+1):
    factorial *= i
  return factorial

# n = int(input("Enter N: "))
# print(f"Factorial of {n} is: {find_factorial(n)}")

def create_table(n):
  for i in range(1,11):
    print(f"{n} x {i} = {n*i}")

# n = int(input("Enter N: "))
# create_table(n)

def check_prime(n) -> bool:
  if n <= 1: return False
  for i in range(2,n):
    if n%i == 0:
      return False
  return True
# n = int(input("Enter N: "))
# if check_prime(n):
#   print(f"{n} is PRIME")
# else:
#   print(f"{n} is NOT PRIME")

def add(a,b):return a+b
def subtract(a,b):return a-b
def multiply(a,b):return a*b
def divide(a,b):return a/b

# a = int(input("Enter 1st No: "))
# b = int(input("Enter 2nd No: "))

# print("Select Calculator Function")
# operation = int(input("1.Add\n2.Subtract\n3.Multiply\n4.Divide"))

# if operation == 1:
#   print(f"Addition of {a} + {b} = {add(a,b)}")
# elif operation == 2:
#   print(f"Subtracting {a} - {b} = {subtract(a,b)}")
# elif operation == 3:
#   print(f"Multiply {a} * {b} = {multiply(a,b)}")
# elif operation == 4:
#   print(f"Dividing {a} / {b} = {divide(a,b)}")
# else:
#   print(f"Invalid Operation")

def reverse_string(str) -> str:
  return str[::-1]

# str = str(input("Enter String: "))
# print(f"Reversal of {str} is {reverse_string(str)}")

def count_vowels(str) -> int:
  count = 0
  for ch in str:
    if ch in 'aeiouAEIOU':
      count += 1
  return count

str = str(input("Enter String: "))
print(f"Vowels in {str} are: {count_vowels(str)}")