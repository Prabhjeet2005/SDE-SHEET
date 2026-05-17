def count_vowels(str) -> str:
  count = 0
  for ch in str:
    if ch in 'aeiouAEIOU':
      count += 1
  return count

str = str(input("Enter String: "))
print(f"Vowels in {str} are: {count_vowels(str)}")