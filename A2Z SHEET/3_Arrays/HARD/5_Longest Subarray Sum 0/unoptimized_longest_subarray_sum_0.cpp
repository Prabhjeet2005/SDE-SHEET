#include <iostream>
#include <vector>
#include<math.h>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {6, -2, 2, -8, 1, 7, 4, -10};
    int size = arr.size();
    int maxLength=0;
    int target = 0;

    for(int i=0; i<size;i++){
      int currentSum = 0;
      for(int j=i;j<size;j++){
        currentSum += arr[j];
        if(currentSum == target){
          maxLength = max(maxLength,j-i+1);
        }
      }
    }

    cout<<"Max Length Subarray Sum Equal 0: "<<maxLength;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << endl;
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}