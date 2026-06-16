/*
Problem:
Every Number Appears 3 times except 1 unique Number

Input:
arr = [2,2,2,7,7,7,5]

Output:
5
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
  /*
  Create a mask(to check for ith number) and count bits using mask for `i` using all elements
  if (number of bits at i ) % 3 != 0, [Here 3 because 3 times repeat]
  then it has unique element bit and set the ith bit for answer here
  */
public:
  void solution()
  {
    vector<int> arr = {2,7,2,2,7,7,3};
    int unique_number = 0;
    for(int i = 0; i<32; i++){
      int mask = (1 << i); // Turn ON ith bit
      int count_i_bits = 0;

      for(auto &element: arr){
        if((element & mask) != 0){ 
          count_i_bits++;
        }
      }

      if(count_i_bits % 3 != 0){
        unique_number = unique_number | mask; // Set i bit for answer
      }
    }
    cout<<"Unique No.: "<<unique_number;
  }
};

int main()
{
  cout << endl;
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}