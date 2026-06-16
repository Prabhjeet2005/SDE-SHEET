/*

### 💻 Phase 1 Boss Challenge: The Twin Paradox

**Problem Statement:**
You are building an anomaly detection system for a server rack. The server logs generate millions of connection IDs. For redundancy, every single connection ID is generated **exactly twice**.

However, during a massive neon storm, a glitch occurred. Exactly **TWO unique connection IDs** were generated only once.

You are given an array `IDs` of size N.
Every number in the array appears exactly twice, except for two numbers that appear exactly once.

Your task is to find and return those two unique numbers.

**Constraints:**
* 2 <= N <= 10^5
* 1 <= IDs[i] <= 10^9
* **Time Limit:** O(N) (You can only loop through the array a couple of times).
* **Space Limit:** O(1) (You **cannot** use a HashMap, HashSet, or Frequency Array. Doing so is an instant failure).

**Sample Input:**

6
4 1 2 1 2 5


**Sample Output:**

4 5


***

### The Architect's Hints (How to think in Bits)

You cannot use a HashMap, so you must use Bit Manipulation.

**Step 1:** If you XOR every single number in the entire array together, all the pairs (like the `1`s and `2`s) will completely annihilate each other because `A ^ A = 0`.
What are you left with? You are left with `4 ^ 5`. Let's call this combined result `XOR_TOTAL`.

**Step 2:** `XOR_TOTAL` is just a number. But what does a `1` inside an XOR result actually mean? It means the two unique numbers have a **different bit** at that exact position! (Because `0 ^ 1 = 1`).

**Step 3:** How do you find a single bit where the two numbers differ? You isolate the rightmost `1` of `XOR_TOTAL` using your new favorite formula: `mask = XOR_TOTAL & (-XOR_TOTAL)`.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {4, 1, 2, 1, 2, 5};
    int total_xor = 0;

    for(auto &element:arr){
      total_xor ^= element;
    }

    // Now i have: 4 ^ 5 result i can isolate them by Rightmost isolation
    // 4 -> 100
    // 5 -> 101

    int rightmost_1 = total_xor & (-total_xor); // Give 001

    /*
    Rightmost 1 is differentiating factor 
    take 2 Buckets now check if that righmost digit 1 -> BUCKET A, if it is 0 -> BUCKET B 
    keep taking XOR Finally we get the answer
    */
    int number1 = 0,number2 = 0;

    for(auto &element:arr){
      // If that bit 1 throw in Bucket A
      if((element & rightmost_1) != 0){ 
        // FIX: Compare with 0 because & used and either give number or 0
        number1 ^= element;
      }else{
        number2 ^= element;
      }
    }

    cout<<"Num1: "<<number1<<"\nNum2: "<<number2;

  }
};

int main()
{
  cout << endl;
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}