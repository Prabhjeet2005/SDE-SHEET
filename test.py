def count_char():
  char_count = {}
  with open("eg.txt","r") as file:
    content = file.read()

    for char in content:
      if char in char_count:
        char_count[char] += 1
      else:
        char_count[char] = 1
  return char_count

char_count = count_char()

for char,count in char_count.items():
  print(f"character: {char}, count: {count}")

