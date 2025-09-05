# KEYWORDS For Revise.md:

- EDGE CASE, FORMULA, NON INTUITIVE

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

- ****Binary Search on 1D*** Use Some Trick to Move in Either of Half (Recognize some pattern)
- **_ANSWER SPACE: _** For Finding Min/Max, Find Min Value, Max Value and apply Binary Search While looping from min <= max look if each possible otherwise go to other half
- One Limit to Another Limit Consecutive Try Apply Binary Search Eg. [minElement,maxElement] or [1,n]
- [No,No,No,Yes,Yes,Yes,Yes] -> Ans Search Space Array Looks Something like this find the min or max

# Binary Search V/s DP
- ![alt text](<images/Screen Shot 2025-08-30 at 2.58.11 AM.png>)
- ![alt text](<images/Screen Shot 2025-08-30 at 2.58.46 AM.png>)


# Maths
## Odd/Even Trick
- Odd + Even -> Odd
- Even + Odd -> Odd
- Odd + Odd -> Even
- Even + Even -> Even

## Find Ceil
- ceil( (double)arr[i] / (double) i )  // DOUBLE is Important otherwise give floor value