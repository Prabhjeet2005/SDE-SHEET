# KEYWORDS For Revise.md:

- EDGE CASE -> Cases that i missed or can miss
- FORMULA -> Formula For Particular question
- NON INTUITIVE -> No intuition almost WROTE Learning
- CONCEPT -> Makes Many Question Clear

# Array Declaration

- int arr[25] = {0};
- STL Sort Override
- std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        // For descending order, we want 'a' to come before 'b' if a.score is greater.
        return a > b;
  });

# Duplicates -> _XOR_

# Subarray/Array Sum -> [PREFIX SUM] _HashMap_ => store sum or element & indexes

- Map Should Be Used For **_LONGEST_**
- ![alt text](images/diagram-export-8-21-2025-11_00_47-PM.svg)

# 2sum/3sum/4sum

- Target - arr[i] or Target - arr[i] + arr[j] or Target - arr[i] + arr[j] + arr[k] then lookup this element in stored set to get other element in O(n) => Better Appproach
- Sort Array & Search Greedily => OPtimized Approach

# [1,n] given think of calculating sum or making 2 equatins of SumN and Sum^2N and solving them

# Count Inversions/Reverse _PAIRS_ (i < j && arr[i]>arr[j]) => Merge Sort

- pairs try to use merge sort if i < j && arr[i] > arr[j] something like this condition

# Binary Search

- **_Binary Search on 1D_** Use Some Trick to Move in Either of Half (Recognize some pattern)
- **_ANSWER SPACE: _** For Finding Min/Max, Find Min Value, Max Value and apply Binary Search While looping from min <= max look if each possible otherwise go to other half
- One Limit to Another Limit Consecutive Try Apply Binary Search Eg. [minElement,maxElement] or [1,n]
- [No,No,No,Yes,Yes,Yes,Yes] -> Ans Search Space Array Looks Something like this find the min or max

## **_Binary Search [Book Allocate, Aggressive Cows, Painter Partition]_**

- greedily take sum and increase count if limit violated

## Binary Search [Decimal] Method

- ![alt text](images/diagram-export-9-8-2025-8_41_01-AM.svg)
- For First 6 Decimal Places Matching
- while(high - low > 1e-6) low = mid , high = mid

# Binary Search V/s DP

- ![alt text](<images/Screen Shot 2025-08-30 at 2.58.11 AM.png>)
- ![alt text](<images/Screen Shot 2025-08-30 at 2.58.46 AM.png>)

# Binary Search Partition

- 2 Array Given assume a partition and decide how many elements to take from smaller size array

# Maths

## LCM

- LCM = |a| \* |b| / GCD(a,b) => Avoid Integer Overflow Multiply |b| seperate
- **_GCD Formula_**
- ![alt text](images/diagram-export-9-9-2025-7_27_35-PM.svg)

## Odd/Even Trick

- Odd + Even -> Odd
- Even + Odd -> Odd
- Odd + Odd -> Even
- Even + Even -> Even

## >> , <<

- \>\> this operator divides number with 2^n [40 \>\> 2 will be 40 / 2^2]
- << this operator multiplies number with 2^n [5 << 3 will be 5 * 2^3]

## Find Ceil

- ceil( (double)arr[i] / (double) i ) // DOUBLE is Important otherwise give floor value

# Strings

- Try To Use Stack If Removal of something or reversing

## STRING STL

- .size(), .empty(), str[0], .front(), .back()
- .push_back() -> Adds Only 1 char, .insert(index,"string"), .erase(index,len), .clear()
- += best for appending a string to another string
- str.find("string") -> return index, .substr(index,len)
- to_string(42), stoi("42"), stod("4.2")

# Linked List [Think in Edge Cases]
- Use Class for using OOPS concepts
- template can be used here
- For Insertion/Deletion at position or value Always take 2 nodes curr & prev
- DELETION delete ptr_name OR free(ptr_name) ===> Free Up The space IMPORTANT

# Heap [Priority Queue]

- When Repeatedly find max or min and array constatntly Change then use HEAP
