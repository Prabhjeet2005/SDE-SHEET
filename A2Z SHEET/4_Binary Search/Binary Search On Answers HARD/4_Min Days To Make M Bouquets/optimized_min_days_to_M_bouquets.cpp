#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int m = 2, k = 3;
    int mini = *min_element(arr.begin(), arr.end());
    int maxi = *max_element(arr.begin(), arr.end());
    int minDays = -1;
    int start = mini,end = maxi;
    while(start <= end){
      int mid = start + (end - start)/2;
      int count = 0,bouquetsFormed=0;
      for(int i=0; i<arr.size();i++){
        if(arr[i] <= mid){
          count++;
        }
        else{
          bouquetsFormed += (count / k);
          count = 0;
        }
      }
      bouquetsFormed += (count/k);
      if(bouquetsFormed >= m){
        minDays = mid;
        end = mid-1;
      }else{
        start = mid+1;
      }
    }
    cout << "Min Days To Form Bouquets: " << minDays;
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