/*
***

### ⚔️ Day 3: The Gauntlet (Story 2)

 **Problem: The Encrypted Comms Channel**

 You are intercepting enemy communications. The enemy transmits a continuous stream of N data packets, represented by an array `packets` where `packets[i]` is an integer.

 The encryption key for any segment of the stream is calculated by taking the **Bitwise XOR** of all the packets in that segment.

 You receive Q decryption requests. Each request gives you a starting packet L and an ending packet R. For every request, you must instantly calculate and output the encryption key for the segment from L to R (inclusive).

 **Constraints:**
 1 <= N <= 10^5
 1 <= Q <= 10^5
 0 <= L <= R < N
 1 <= packets[i] <= 10^9

***
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
    vector<int> arr = {};
    vector<vector<int>>queries={};
    int N;
    vector<int>prefix_xor(N+1,0);
    int total_xor = 0;
    for(int i=1; i<=arr.size(); i++){
      prefix_xor[i] = arr[i-1] ^ prefix_xor[i-1];
    }
    vector<int>result(queries.size(),0);
    for(int i=0; i<queries.size(); i++){
      int l = queries[i][0];
      int r = queries[i][1];
      result[i] = prefix_xor[r+1] ^ prefix_xor[l-1+1]; // +1 for 1 based index
    }

    for(auto &element: result){
      cout<<element<<" ";
    }
  }
};

int main()
{
  cout << endl;
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}