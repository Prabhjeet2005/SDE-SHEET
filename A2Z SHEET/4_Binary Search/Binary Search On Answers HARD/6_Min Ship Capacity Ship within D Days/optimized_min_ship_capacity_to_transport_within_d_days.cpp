#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {5, 4, 5, 2, 3, 4, 5, 6};
    int daysTarget = 5;
    int finalMinCapacity = -1;
    int sumArr = accumulate(arr.begin(), arr.end(), 0);
    int maxi = *max_element(arr.begin(), arr.end());

    int start = maxi,end = sumArr;
    while(start <= end){
      int mid = start + (end-start)/2;
      int days = 1,currentLoad=0;

      for(auto & package:arr){
        if(currentLoad + package > mid){
          days++;currentLoad = package;
        }else{
          currentLoad += package;
        }
      }

      if(days <= daysTarget){
        finalMinCapacity = mid;
        end = mid-1;
      }else{
        start = mid+1;
      }
    }
    cout << "Min Capacity Required: " << finalMinCapacity;
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