def reverse_string(str) -> str:
  return str[::-1]

str = str(input("Enter String: "))
print(f"Reverse of {str} is: {reverse_string(str)}")