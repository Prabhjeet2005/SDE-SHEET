a = int(input("Enter 1st No: "))
b = int(input("Enter 2nd No: "))
c = int(input("Enter 3rd No: "))

if a >= b and a >= c:
  print("A Largest")
elif b >= a and b >= c:
  print("B Largest")
else:
  print("C Largest")