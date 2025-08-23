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

### **_HINT_ -> SUBARRAY THINK OF PREFIX SUM with MAP**

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

### 13. Length of Longest Subarray [ **CONTIGOUS** ] with sum K (POSITIVES & NEGATIVES) [*PREFIX SUM*]

**UNOPTIMIZED APPROACH**

- for each element check its subarray (contigous) calculate if sum equal to K then store max length by inner loop index - outer loop index

**OPTIMIZED APPROACH [PREFIX SUM]**

- Track current sum of array & max Size
- if sum == k , then update max size
- if sum - k found in map then update max size
- Store every sum along with their index in unordered_map if not already present

## **MEDIUM**

### 1. 2 Sum [**1 pass sum think of hashmap**]

#### **UNOPTIMIZED APPROACH**

- take 2 loops check each combo if sum == target then print yes and indexes

#### **OPTIMIZED APPROACH 1**

- **FORMULA: Target - arr[i]**
- Store Each Element in unordered_map
- check if target - currentElement present in map, if present then return yes & currentElement, {target-currentElement}

#### **OPTIMIZED APPROACH 2 [GREEDY]**

- Sort the Array
- Take 2 Pointer Beginning and end
- if begin + end < target then begin++ otherwise end++

### 2. Sort Array of 0, 1 ,2

#### **UNOPTIMIZED APPROACH**

- Sort The Array Using Sorting Algorithm

#### **BETTER APPROACH**

- count no. of 0, 1, 2 and then populate them back into the array

#### **OPTIMIZED APPROACH [ *DUTCH FLAG ALGORITHM* ]**

- 3 Pointer Approach ( low, mid, high )
- if element at mid == 0, then swap low and mid and low++, mid++
- if element at mid == 1, then mid++
- if element at mid == 2, then swap mid and high, and high--

### 3. Majority Element ( > n/2)

#### **UNOPTIMIZED APPROACH**

- for each element traverse array again and count number of occurernces & store the max count

#### **BETTER APPROACH**

- Store Each frequency of element in HASHMAP
- Return the Maximum Frequency Element

#### **OPTIMIZED APPROACH [*Moore's Voting Algorithm*]**

- store majortyElement and Count
- check if element same as majority element with count > 0, then increase count
- if count == 0 , then update majorityElement and increase count

### 4. Kadane Algorithm [Maximum Subarray Sum]

#### **UNOPTIMIZED APPROACH**

- Take 2 loops check each and every subarray sum and store the sum, and start index and end index array to print maximum subarray sum

#### **OPTIMIZED APPROACH [ *KADANE* ]**

- Just DO **sum += arr[i]**
- Keep track of current sum
- store maximum sum & if sum < 0, then sum = 0
- temporary starting index will update to current Index whenever currentSum == 0
- Also For Array start & end index -> _whenever max sum updated_ then update end Index & actual start Index with temporary starting index

### 5. Stock Buy & Sell [ Buy Early Sell Later ]

#### **UNOPTIMIZED APPROACH**

- Calcuate each and every profit
- store max Profit

#### **OPTIMIZED APPROACH**

- Store Minimum Element and store maximum profit as difference between currentElement and MinElement

### 6. Alternate Positive & Negative Element in Array [start positive]

#### **OPTIMIZED APPROACH**

- Create answer array
- put all positive element in even places & negative elements in odd places
- if either negative or positive have exhausted
- insert remaining positive or negative [only 1 type remains if excess]

### 7. Next Permutation ( Time Complexity To Generate All Permutation -> N! )

#### **UNOPTIMIZED APPROACH**

- generate all permutations
- search for current permutation & print the next element
- EDGE: if it is the last element return the first element otherwise return the

##### _GENERATING ALL PERMUTATIONS [swap indexes] TC-> O( N! x N )_

- Using **Recurion** & **Backtracking**
- for each index loop till rest of array
- swap index with iterator
- Call recursive function with index + 1
- BACKTRACK: swap back the iterator with index

#### **STL APPROACH**

- Use _next_permutation()_

#### **OPTIMIZED APPROACH [ Break Point ]**

- ![alt text](images/diagram-export-8-17-2025-8_14_44-PM.svg)

- Longest Prefix Match arr[i] < arr[i+1] --> This is the BREAK Point _{ Check From Right }_
- Select greater than current element arr[i] but the smallest one from after the break line i.e i+1 & greater index
- if no index found then reverse entire array
- if index found then from right just greater element swap with arr[i]
- reverse array after break point

### 8. Leaders In Array

#### **UNOPTIMIZED APPROACH**

- For Each Element Check if It is Maximum

#### **OPTIMIZED APPROACH**

- From right carry the maximum element
- if currentElement > maximumElement then store currentElement into Leaders array

### 9. Longest Consecutive Subsequence

#### **UNOPTIMIZED APPROACH**

- For Each Element check if element+1, element+2,...element+arr.size() are present
- if not present then break and store highest length

#### **BETTER APPROACH**

- Sort The Array
- check next element same if not then set current length = 0 & store max length

#### OPTIMIZED APPROACH _[ SET ]_

- **[Consecutive -> Must be 1st Element of the sequence for OPTIMIZATION]**
- Using Set Data Structure Store All elements
- Check if _element-1 exists, then continue_ as it can't be starting of longest subsequence
- otherwise element-1 not exist, then search element+1,element+2,....,element+arr.size() & store the maximum length

### 10. Set Matrix Zero

#### **UNOPTIMIZED APPROACH**

- whenever 0 encountered make entire row and column -1 except 0 elements
- Again traverse and replace -1 with 0

#### **BETTER APPROACH [SC ↑]**

- Maintain Two Array for Row and Col
- if 0 encountered mark index of Row and Col to be true
- traverse wherever row or col 0 encountered make entire row & col 0

#### **OPTIMIZED APPROACH**

- **EDGE CASE:** Keep track of 0 in row0 and col0 seperately
- Mark in first Row All the columns having 0 & in first Col mark for each row having 0
- {Suppose 1st Col has 0 if we depend upon 1st col for row 1 then row 1 also become all zero}
- Again traverse from 1st index as we don't want to change either row or col
- if anywhere in row0 or col0 element 0 is found make entire row or col 0
- finally check if row0 or col0 is true then make them entire 0

### 11. Rotate Matrix 90 Degree

#### **UNOPTIMIZED APPROACH**

- Take Another Answer array for each row make each col of ans array from last same

#### **OPTIMIZED APPROACH**

- Transpose Matrix
- then reverse each row

### 12. Print Matrix Spiral

- _GO LAYER BY LAYER_
- take 4 variables startRow = 0, endRow = n-1, startCol = 0, endCol = n-1
- print startCol -> endCol each element of startRow, then startRow++
- print startRow -> endRow each element of endCol, then endCol--
- print endCol -> startCol each element of endRow, then endRow--
- print endRow -> startRow each element of startCol, then startCol++

### 13. Count Subarray Sum Equal To K

#### **UNOPTIMIZED APPROACH**

- Calculate each and every subarray and if subarray sum == k increase the count

**BETTER APPROACH [PREFIX SUM]**

- ![alt text](<images/Screen Shot 2025-08-18 at 11.21.55 AM.png>)
- Track current sum of array & store sum & its index in map or set
- if sum == k , then increase count
- if sum - k found in map or set then update count
- Store every sum along with their index in unordered_map if not already present

**OPTIMIZED APPROACH**

- Initialize 2 pointers (left,right)
- right adds each and every element
- while left <= right & at any time current Sum > k then remove arr[left] from sum
- if sum == k ,then increase the count
- increase right & check if < arr.size() , then add next element to sum

## **HARD**

### 1. Pascal Triangle

- ![alt text](<images/Screen Shot 2025-08-18 at 12.01.43 PM.png>)
- ![alt text](images/diagram-export-8-18-2025-11_59_51-AM.svg)

#### _VARIATION 1_

- _Given Row & Col Index Give Element At Pascal Triangle (row,col) position_
- use formula row-1 C col-1
- nCr -> n! / (r! \* (n-r)!)

#### _VARIATION 2_

- Same as variaion 1 just go for entire col same as length of row keep row same

#### _VARIATION 3_

- add another loop to manage row as well & make col go from 0 < loop1 + 1

### 2. Majority Element Array _[ > N ÷ 3 ]_

- _There Can be Only 2 Elements >N/3_

#### **UNOPTIMIZED APPROACH**

- Check For each & every Element if greater than N/3, then add to answer array

#### **BETTER APPROACH**

- Keep Track of Frequency Of All Elements in Unordered_map if frequency > N/3, then store element in Answer

#### **OPTIMIZED APPROACH _[Extended Morre's Voting Algorithm]_**

- ![alt text](<images/Screen Shot 2025-08-19 at 7.12.53 PM.png>)
- Create 4 Pointers _{2 for tracking element count & 2 for storing max element}_
- if Count == 0 && currentElement != otherElement ,then reset count=1 & UPDATE element stored to current Element
- **_EDGE CASE:_** When checking for an element make sure current element != other stored element
- if current element same as stored element increase count
- if current Element not equal to stored element decrease count
- After Looping through array Again calculate respective count of both the element
- if count > N/3 then store it in answer

### 3. 3 Sum Equal to target

#### **UNOPTIMIZED APPROACH**

- _set<vector<int>> to vector<vector<int>>_
- Run 3 Loops 0 to n-1, i+1 to n-1, j+1 to n-1
- if sum == target store the triplet in **IMPORTANT:** SORTED MANNER {To Check Existence of same triplets} otherwise their order might be different and we could add same triplets

#### **BETTER APPROACH _[2 Pointer Approach With 3rd Element as Lookup]_**

- **_FORMULA: Target - (arr[i]+arr[j]+arr[k])_**
- traverse each element
- Declare another hashset to store 2nd element
- run another loop from i+1 to n
- check if 3rd Element = target - (arr[i] + arr[j]) is Present in set of visited elements
- if visited then store triplet
- at last transfer set< vector< int >> to vector< vector< int >>
- **_ORDERED SET SHOULD BE USED Only it can store set<vector<int>>_**

#### **OPTIMIZED APPROACH**

- Sort the array
- take 3 pointers i=0,j=i+1,k=n-1
- skip duplicates of ith pointer
- if sum > target => k--
- if sum < target => j++
- **_EDGE CASE: Ensure Duplicates Removed_**
- if sum == target => Store Triplet & keep increasing and decreasing 2nd and 3rd pointer to avoid duplicates

### 4. 4 Sum Equal to target

#### **UNOPTIMIZED APPROACH**

- Take 4 Loops And Calculate sum whether equal to target, if equal then sort and store it in set of vectors

#### **BETTER APPROACH [Loop + Loop + Set{For Lookup} + Loop]**

- **_FORMULA: 4th Element = target - (arr[i]+arr[j]+arr[k])_**
- Take 3 Loops
- first loop iterate each element
- second loop iterate i+1 to n-1
- before 3rd Loop create a set for visited elements
- 3rd loop have **_4th Element = target - (arr[i]+arr[j]+arr[k])_** if present in set then we found the 4 numbers equating to sum target now sort and add them to set

#### **OPTIMIZED APPROACH [Loop + Loop + Set{For Lookup} + 2 Pointer]**

- Sort the array
- Take 4 Pointer (2 Fixed, 2 moving)
- 2 Moving 1->start, 1->end
- **_IMPORTANT: Check Duplicate at every loop_**
- if sum == target => store answer and move forward/back till no longer duplicate
- sum < target => pointer3++
- sum > target => pointer4--

### 5. Longest Subarray With Sum 0

#### **UNOPTIMIZED APPROACH**

- Check Each and Every Subarray Sum == 0, then store longest length

#### **OPTIMIZED APPROACH [Use HashMap Only]**

- Calculate Prefix sum
- for each element check whether currentSum - target is present or not
- if present store maxLength
- Store sum in unordered_map along with index

### 6. Count Subarrays with XOR Target

#### **UNOPTIMIZED APPROACH**

- Calculate XOR of Each and every subarray & if XOR == Target, then count++

#### **OPTIMIZED APPROACH**

- **_EDGE CASE:_** Do map[0]++, Because if first element is equal to xor of target then we find xor ^ target which will be 0 and it isn't included in map yet
- Store Xor in Prefix Xor, then store in hashmap
- for each element check XOR ^ CurrentXOR if Present in Hashmap then increase the count, otherwise insert current XOR in Hashmap

### 7. Merge Overlapping Subintervals

#### **UNOPTIMIZED APPROACH**

- SORT the Array
- store start & end of interval
- **_EDGE CASE:_** if end <= ans.back()[1] which means it has already been merged so continue
- check from i+1 < n whether start <= currentElement[0] if true then update end
- else break
- push_back start & end in ans

#### **OPTIMIZED APPROACH**

- SORT the Array
- push_back first element in answer
- in a single pass we will check
- **_CASE 1:_** if current element's start <= end of ans.back() then update answer's end to max(currentElement's end, ansElement's end )
- **_CASE 2:_** otherwise store the entire interval in answer

### 8. Merge 2 Sorted Arrays

#### **UNOPTIMIZED APPROAACH**

- Take 2 Pointers in start of both arrays whichever smaller push to answer array

#### **OPTIMIZED APPROACH 1**
- [Picking up greater elements of array1 & swapping to arr2 until they become equal or greate so that all larger elements go into arr2]
- Take 2 pointers 1 in end of 1st array in start of 2nd array
- if element at ptr1 > ptr2 then swap arr1[ptr1--] & arr2[ptr2++]
- if element at ptr1 <= ptr2 then break
- Individually sort arr1 & arr2


