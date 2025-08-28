#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int peakIndex = -1;
    if(arr.size()==1)peakIndex=0;
    if(arr[0]>arr[1])peakIndex = 0;
    if(arr[arr.size()-1] > arr[arr.size()-2])peakIndex=arr.size()-1;
    if(peakIndex != -1){
      cout<<"Peak Index: "<<peakIndex;return;
    }

    int start = 1,end = arr.size()-2;

    while(start<=end){
      int mid = start + (end - start)/2;
      if(arr[mid] > arr[mid-1] && arr[mid]>arr[mid+1]){
        peakIndex=mid;
        break;
      }
      if(arr[mid-1]<arr[mid] && arr[mid]<arr[mid+1]){
        start = mid+1;
      }else{
        end = mid-1;
      }
    }
    cout<<"Peak Index: "<<peakIndex;
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