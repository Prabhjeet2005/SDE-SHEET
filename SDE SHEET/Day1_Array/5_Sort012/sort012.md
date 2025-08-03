Unoptimised
Make unordered map and store number of 0 1 2 and then populate them again

Optimised      [ Take 3 Pointers  ]
low=0 , mid = 0, high = size - 1

move mid pointer if it encounters 
nums[mid] == 0 then swap with low and move low ++ and mid ++
nums[mid] == 1 then mid++
nums[mid] == 2 then swap mid and high and move high--