#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  void calculateSum(vector<int>&arr,int &currentSum,int divisor,int threshold){
    for(auto &element:arr){
      currentSum += ceil((double)element/ (double)divisor);
      if(currentSum > threshold)return;
    }
  }

public:
  void solution()
  {
    vector<int> arr = {8, 4, 2, 3};
    int threshold = 10, ans = -1;
    int maxi = *max_element(arr.begin(), arr.end());

    int start =1,end = maxi;
    while(start <= end){
      int mid = start + (end - start)/2;
      int currentSum = 0;
      calculateSum(arr,currentSum,mid,threshold);
      if(currentSum <= threshold){
        ans = mid;
        end = mid-1;
      }else{
        start = mid+1;
      }
    }
    cout << "Minimum divisor: " << ans;
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