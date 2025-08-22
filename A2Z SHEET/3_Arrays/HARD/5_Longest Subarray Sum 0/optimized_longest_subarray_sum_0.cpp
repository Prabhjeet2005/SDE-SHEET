#include <iostream>
#include <vector>
#include <math.h>
#include<unordered_map>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {6, -2, 2, -8, 1, 7, 4, -10};
    int size = arr.size();
    int maxLength = 0, currentSum = 0;
    int target = 0;
    unordered_map<int,int>map;
    map.reserve(size);
    map.max_load_factor(0.7f);

    for (int i = 0; i < size; i++)
    {
      currentSum += arr[i];
      if(currentSum == target){
        maxLength = i+1;
      }
      else if(map.find(currentSum - target) != map.end()){
        maxLength = max(maxLength,map[currentSum - target] + 1);
      }else{
        map[currentSum] = i;
      }
    }

    cout << "Max Length Subarray Sum Equal 0: " << maxLength;
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