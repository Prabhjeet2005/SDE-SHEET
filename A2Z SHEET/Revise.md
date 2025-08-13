# DSA REVISION

# Step 1: Basics

## Patterns

## Learn STL

## Basic Maths

### 1. Count Digits

#### **UNOPTIMISED APPROACH**

- Create A Counter, ÷ Each Number By 10 and Increase Counter

### 2. Reverse A Number

#### **OPTIMISED APPROACH**

- Take Remainder
- Check if FinalAns > INT_MAX/10 || FinalAns < INT_MIN/10
- Multiply Final Ans by 10 and Add Remainder

### 3. Check Palindrome Number

#### **OPTIMISED APPROACH**

- If Negative Number Then Return False
- First Calculate Reverse
- If Reverse and Original No. Same Then it Is A Palindrome

### 4. GCD or HCF

#### **UNOPTIMISED APPROACH**

- Loop from 1 to min(num1,num2)
- Divide Each Number With min(num1,num2)
- Return the Final Answer

#### **BETTER APPROACH**

- Loop from min(num1,num2) to 1
- Divide Each Number With min(num1,num2) if Found Then Break
- Return the Final Answer

#### **OPTIMISED APPROACH [Euclidean Algorithm]**

- Subtract & Update Lesser Number From Greater Number
- Keep Repeating This Step Till Any One Number is 0
- After any no. is 0 return the other number.

### 5. ArmStrong Number

#### **OPTIMISED APPROACH**

- Initialize Armstrong Sum = 0
- Calculate Remainder and Then Divide By 10
- Add Remainder _ Remainder _ Remainder to Armstrong Sum
- If Armstrong Sum == number, Then it is an Armstrong Number

### 6. Print All Divisors Of Given Number

#### **UNOPTIMISED APPROACH**

- From Number till 1 Add To Set if Number % iterator == 0

#### **OPTIMISED APPROACH**

- Run A For Loop From 1 to <= sqrt(n)
- if n % i == 0, {
  then i is a divisor,
  if(n/i != i){ // Not 6 x 6 =36 i.e it's counter part is different
  then n/i is also a divisor
  }
  }
- ![alt text](<images/Screen Shot 2025-08-05 at 9.24.13 AM.png>)

### 7. Check if Number is Prime

#### **UNOPTIMISED APPROACH**

- Initialize flag = false
- Run a for loop from 2 till < n , If n % iterator == 0 -> flag=true
- if flag is false then it is a prime, otherwise not a prime

#### **OPTIMISED APPROACH**

- Initialize flag = false
- Run a for loop from 2 till < sqrt(n) , If n % iterator == 0 -> flag=true
- if flag is false then it is a prime, otherwise not a prime

## Basic Recursion

### 3. Print 1 To N

#### **APPROACH 1**

- Run Recursion From n and also store current value as 1 solve(1,n)
- each step solve(current + 1, n)
- Base Condition current > n

#### **APPROACH 2 [BACKTRACKING]**

- Run Recursion From n
- After solve(n-1) write the print Statement (BACKTRACKING)
- ![alt text](<images/Screen Shot 2025-08-05 at 6.49.25 PM.png>)

### 5. Sum 1 To N

#### **APPROACH [Recursion]**

- Run Recursion From n and also store current sum as 0 solve(n,sumFirstN)
- Base Condition if(n <= 0)
- While Backtracking return sumFirstN += end

### 7. Reverse An Array

#### **APPROACH 1 [2 Pointer]**

- Run A For Loop
- Using 2 Pointer Technique to swap(arr[i],arr[n-i-1])

#### **APPROACH 2 [RECURSION]**

- Recursion Function Pass Array and iterator=0
- Base Condition iterator >= arr.size()/2
- swap(arr[iterator],arr[size - iterator - 1])

### 8. Check Palindrom String With Other Special Characters

- ![alt text](<images/Screen Shot 2025-08-05 at 7.47.32 PM.png>)

#### **APPROACH [2 Pointer]**

- Initialize 2 Pointers start=0 & end = str.size() - 1
- check if( !isalnum(str[start]) ) then start++
- else if( !isalnum(str[end]) ) then end--
- else if( tolower(str[start]) != tolower(str[end]) ) then return Not Palindrome
- else start++,end--

### 9. Nth Fiboonacci Number

#### **APPROACH**

- Recursion from n
- each recursion return fibo(n-1) + fibo(n-2)

## Hashing

### 1. Count Frequency Of All Elements

#### **UNOPTIMIZED APPROACH**

- Create a visited array of size n
- run a for loop from 0 to < n, if element already visited then continue
- otherwise mark the element visited and initialize count=0 and run another for loop that counts the occurence of element in array
- Print the Count

#### **OPTIMIZED APPROACH**

- Create an unordered_map < int,int > to store each element count
- Run a For loop map[arr[i]]++
- then print the map by map.first and map.second

### 2. Max/Min Frequency Out Of All Elements

#### **OPTIMIZED APPROACH**

- Create an unordered_map < int,int > to store element and its freq
- Run a For Loop to store into map each freq
- initialize min_value,min_element, max_value,max_element
- Iterate Through The Map update min/max value by checking for min()/ max() of it.second and current min or max values, if value updates to current value then update min/max element by iterator.first

# Step 2: Important Sorting Techniques

### 1. Selection Sort [Select Min Element From rest of array & swap]

- ![alt text](<images/Screen Shot 2025-08-06 at 8.10.47 PM.png>)
- Run Outer For Loop Iterating Each Index 0 to n
- Initialize Minimum_Index = i
- Run Inner For Loop i+1 to n
- Select the most min element from rest of array and store it's index in Minimum_Index
- Swap Minimum_Index Element with Current Element

### 2. Bubble Sort [check next element if it is smaller then swap]

- Run For Loop From i=0 to i < n
- Run Inner For Loop from j=0 to j = n - i - 1 [Because we check arr[j] > arr[j+1] Which can Go Out of Bounds]
- if ( arr[j] > arr[j+1] ) then swap( arr[j], arr[j+1] )
- check if swap took place in loop otherwise break because array sorted

### 3. Insertion Sort [For Each Element Put it into its Correct Place On its left]

- ![alt text](<images/Screen Shot 2025-08-06 at 8.44.46 PM.png>)

- Run For Loop From i=0 to i < n
- Run Another Inner Loop From j = i to j > 0
- Check if( arr[j] < arr[j-1] ) then swap them, otherwise break inner loop because array sorted uptil current Element

### 4. Merge Sort [Divide & Conquer (Divide Search Space then recombine in sorted manner)]

- ![alt text](<images/Screen Shot 2025-08-06 at 9.19.30 PM.png>)

- Create 2 Functions merge_sort() and merge()
- in merge_sort Call merge_sort from low to mid & mid+1 to high
- After call merge function
- In merge() create a temporary array & initialize left = low, right = mid+1
- create a while loop (left<=mid && right <= high )
- create inner while loops which will insert the minimum of arr[left],arr[right] to temporary array
- After Insert Remaining of left <= mid or right <= high
- Create a For Loop to replace original array elements with sorted temporary elements

### 5. Quick Sort [Divide & Conquer ( Pick A Pivot Element & Swap it by counting elements <= pivotElement )]

- Create a quick sort function which has another partition function
- After partition call quickSort(arr,low,partition-1), quickSort(arr,partition+1,high)
- partition(arr,low,high) function SWAPS the first element of current subarray with the number of elements <= arr[low]
- initialize left = low,right =high
- Create a while loop (left < pivotIndex && right > pivotIndex)
- Create Inner While Loops where left < pivotElement then left++
- Create Inner While Loops where right > pivotElement then right--
- Again Check if left < pivotIndex && right > pivotIndex , then swap( arr[left++],arr[right--])
- return pivotIndex

# Step 3. Arrays

## **EASY**

### 1. Largest Element In An Array

**APPROACH**

- Initialize a maxi = INT_MIN variable
- Compare each element in array and store maximum element maxi = max(maxi,arr[i])

### 2. Second Largest/Smallest Element In An Array

**UNOPTIMIZED APPROACH**

- Sort the Array
- Second Index -> 2nd Smallest, Last Second Index -> 2nd Largest

**OPTIMIZED APPROACH [EDGE CASE]**

- initialize smallest,second_smallest,largest,second_largest
- Run A Loop From 0 to n
- if arr[i] > largest, then store largest in second_largest & update largest = arr[i]
- **EDGE CASE [Beacause Largest can be the first element]** else if arr[i] < largest && arr[i] > second_largest, update second_largest = arr[i]
- if arr[i] < smallest , then store smallest in second_smallest & update smallest = arr[i]
- **EDGE CASE [Beacause Smallest can be the first element]** else if arr[i] > smallest && arr[i] < second_smallest, then update second_smallest = arr[i]
- return second_largest & second_smallest

### 3. Check Is Array Sorted

**OPTIMIZED APPROACH**

- Run A Loop from 0 to n
- if at any point (currentElement > nextElement) return false
- otherwise return true

### 4. Remove Duplicate Elements From Sorted Array [inplace, print first k elements which are non duplicated]

**UNOPTIMIZED APPROACH**

- Create A Set And set.insert(arr[i]) all elements
- Initialize (i=0) & iterate through the set and set arr[i++] = iterator_set

**OPTIMIZED APPROACH**

- Initialize current Index = 0
- Run a Loop From iterator=1 to n
- if {_DUPLICATE ENCOUNTERED_} arr[iterator] == arr[currentIndex], then continue
- otherwise (_Not Duplicate Encountered_) increase currentIndex += 1 & store arr[currentIndex] = arr[iterator]
- print Array of removed duplicates from 0 to <= currentIndex

### 5. Left Rotate Array By 1 Place

**APPROACH 1**

- ![alt text](<images/Screen Shot 2025-08-08 at 10.05.34 AM.png>)
- Store the First Element
- From i=0 to i < n-1 ,store arr[i] = arr[i+1]
- assign last element arr[n-1] = firstElement

**APPROACH 2 [STL]**

- Store First Element
- Erase first element
- push_back first element

### 6. Left/Right Rotate Array By K Place

**UNOPTIMIZED APPROACH**

- if rotate by left
- store first k elements in temp array
- erase first k elements
- push_back first K elements back to array

- if rotate by right
- store last k elements in temp array
- erase last k elements
- .insert temp elements back to array

**OPTIMIZED APPROACH [REVERSE ALGORITHM]**

- create a reverse function
- if rotate by left
- reverse first k elements
- reverse rest of elements
- reverse all elements

- if rotate by right
- reverse last k elements
- reverse rest of elements
- reverse all elements

### 7. Move All Zeroes To End

**OPTIMIZED APPROACH 1**

- count all zeroes
- erase all zeroes
- push_back zeroes count times

**OPTIMIZED APPROACH 2 [TRICKY]**

- ![alt text](<images/Screen Shot 2025-08-08 at 11.46.02 AM.png>)
- Create 2 Pointers
- ptrZero points to First Occurence 0
- ptrNonZero points to NON 0 element (_Just After ptrZero pointer_)
- if (arr[i] != 0) then swap the ptrZero and ptrNonZero & move ptrZero++ because now it points to just next zero

### 8. Join 2 Sorted Arrays while removing duplicates

**UNOPTIMIZED APPROACH**

- create an Ordered Set
- insert into set values of array1 and array2
- traverse set and push_back into ans array

**OPTIMIZED APPROACH**

- create 2 pointer to keep track each array element
- whichever ptr element is lower && is not equal to ans.back() element will be added
- Enter All Remaining Elements of either Array1 OR Array2 && they should != ans.back()

### 9. Missing Number In Array [*Duplicate Try to Use XOR*]

**UNOPTIMIZED APPROACH**

- for each element check if the element exists in entire array if not then found the missing number

**BETTER APPROACH**

- Create an unordered set insert each element in it
- again traverse through array and .find() each element if iterator == set.end() then found the missing element

**OPTIMIZED APPROACH 1**

- Calculate sumN from 1 to n => (N \* (N + 1))/ 2
- calculate sum of array
- Missing Number = sumN - sum of Array

**OPTIMIZED APPROACH 2**

- Calculate XOR of 1 to N
- Calculate XOR of Array
- Calculate XOR of 1 To n ^ XOR of Array [ XOR Of Same No. Will be 0 & XOR of 0 with a number returns Number itself] gives missing number
- EXAMPLE:
- XORN : 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 7 ^ 8 ^ 9 ^ 10 ^ 11
- XORArray: 1 ^ 2 ^ 3 ^ 4 ^ 5 ^ 6 ^ 8 ^ 9 ^ 10 ^ 11
- RESULT : 0 ^ 0 ^ 0 ^ 0 ^ 0 ^ 0 ^ 7 ^ 0 ^ 0 ^ 0 ^ 0 => 7

### 10. Max Count of 1's in array of only 0 & 1

**OPTIMIZED APPROACH**

- Keep track of current count of 1 and maximum count of 1
- if 0 is encountered reset current count

### 11. Find Number Appearing Once With Array of elements occuring twice [*Duplicate Try To Use XOR*]

**UNOPTIMIZED APPROACH**

- Create a Unordered HashMap store every element frequency
- return element with frequecy as 1

**OPTIMIZED APPROACH**

- Find XOR Of All Elements
- {_Same Elements XOR will be 0 & finally XOR with 0 returns number itself_}
- return XOR

[ **PREFIX SUM** ]

### 12. Length of Longest Subarray [ **CONTIGOUS** ] with sum K (POSITIVES ONLY)

**UNOPTIMIZED APPROACH**

- for each element check its subarray (contigous) calculate if sum equal to K then store max length by inner loop index - outer loop index

**BETTER APPROACH [PREFIX SUM]**

- Track current sum of array & max Size
- if sum == k , then update max size
- if sum - k found in map then update max size
- Store every sum along with their index in unordered_map if not already present

**OPTIMIZED APPROACH**

- Initialize 2 pointers (left,right)
- store first element in sum
- when sum > k subtract current element from sum
- if sum == k store current length
- if right < n then add element in sum

### 13. Length of Longest Subarray [ **CONTIGOUS** ] with sum K (POSITIVES & NEGATIVES)

**UNOPTIMIZED APPROACH**

- for each element check its subarray (contigous) calculate if sum equal to K then store max length by inner loop index - outer loop index

**OPTIMIZED APPROACH [PREFIX SUM]**

- Track current sum of array & max Size
- if sum == k , then update max size
- if sum - k found in map then update max size
- Store every sum along with their index in unordered_map if not already present


## **MEDIUM**