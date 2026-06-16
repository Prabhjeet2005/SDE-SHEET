/*

### 💻 Phase 1 Extension: Reversing Bits (LeetCode 190)

**The Problem:** You are given a 32-bit unsigned integer. You must reverse the order of its bits and return the new integer.
*(For example, if the binary string is `00000010`, the reverse is `01000000`).*

Input:
19

Output:
200

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
  /*
  CONVEYOR BELT ANALOGY
  Take result
  shift it << to make space for the box
  [We Will take all bits] Now take rightmost bit (can be 0 or 1) using
  righmost = N & 1
  now set the bit result = result | rightmost
  now Delete the box of number = number >> 1

  */
public:
  void solution()
  {
    unsigned int num = 19; // Ouptut 200
    unsigned int result = 0;
    for (int i = 0; i < 32; i++)
    {
      int rightmost_bit_num = num & 1;
      result = result << 1;                // Make space
      result = result | rightmost_bit_num; //  Update the righmost bit
      num = num >> 1;                      // Delete Rightmost bit
    }

    cout << result;
  }
};

int main()
{
  cout << endl;
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}