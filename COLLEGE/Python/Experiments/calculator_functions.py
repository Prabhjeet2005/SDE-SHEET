def add(a,b): return a + b
def subtract(a,b): return a - b
def divide(a,b): return a / b
def multiplication(a,b): return a * b

a = int(input("Enter 1st No: "))
b = int(input("Enter 2nd No: "))

print("Calculator:")
print(f"{a} + {b} : {add(a,b)}")
print(f"{a} - {b} : {subtract(a,b)}")
print(f"{a} / {b} : {divide(a,b)}")
print(f"{a} * {b} : {multiplication(a,b)}")


