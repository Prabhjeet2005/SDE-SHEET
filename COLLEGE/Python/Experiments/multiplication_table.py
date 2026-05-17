def multiplication_table(n):
  for i in range(1,11,1):
    print(f"{n} x {i} = {n*i}")
  
n = int(input("Enter N:"))
multiplication_table(n)