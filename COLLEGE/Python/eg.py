def generate_odd(curr,count=0):
  if count == 10:
    return
  print(curr)
  generate_odd(curr+2,count+1)

  return

generate_odd(1,0)