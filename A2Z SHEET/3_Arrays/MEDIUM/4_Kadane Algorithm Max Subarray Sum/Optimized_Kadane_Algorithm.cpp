#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int startIndex = -1;
    int tempStart = 0;
    int endIndex = -1;
    int maxSum = 0;
    int currentSum = 0;

    for(int i=0; i<arr.size(); i++){
      if(currentSum == 0){
        tempStart = i;
      }
      currentSum += arr[i];
      if(currentSum > maxSum){
        maxSum = max(maxSum,currentSum);
        startIndex = tempStart;
        endIndex = i;
      }
      if(currentSum < 0){
        currentSum = 0;
      }
    }
   
    cout << "Max Subarray Sum: " << maxSum << endl;
    for (int i = startIndex; i <= endIndex; i++)
    {
      cout << arr[i] << ", ";
    }
    cout << endl;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}