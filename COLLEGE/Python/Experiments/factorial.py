
def find_factorial(n) -> int:
  ans = 1
  for i in range(1,n+1,1):
    ans *= i
  return ans


n = int(input("Enter N:"))
print(f"Factorial of {n} is: {find_factorial(n)}")