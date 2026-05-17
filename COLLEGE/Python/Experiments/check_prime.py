def check_prime(n) -> bool:
  for i in range(2,n):
    if n%i == 0:
      return False
  return True

n = int(input("Enter Number: "))
if check_prime(n):
  print(f"{n} is Prime")
else:
  print(f"{n} is Not Prime")