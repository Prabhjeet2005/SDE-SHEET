
n = int(input("Enter N: "))
first = 0
second = 1

for i in range(0,n,1):
  if i <= 1:
    print(i,end=", ")
  else:
    temp = first
    first = second
    second = temp + second
    print(second,end=", ")
  
