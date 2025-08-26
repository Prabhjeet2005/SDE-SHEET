#include <iostream>
#include <vector>

using namespace std;

class Solution
{
  void find_firstOccurence(vector<int>&arr,int start,int end,int &firstOccurence,int target){
    while(start <= end){
      int mid = start + (end - start)/2;
      if(arr[mid] == target){
        firstOccurence = mid;
        end = mid-1;
      }else if(arr[mid] > target){
        end = mid - 1;
      }else{
        start = mid +1 ;
      }
    }
  }
  void find_lastOccurence(vector<int>&arr,int start,int end,int &lastOccurence,int target){
    while(start <= end){
      int mid = start + (end - start)/2;
      if(arr[mid] == target){
        lastOccurence = mid;
        start = mid+1;
      }else if(arr[mid] > target){
        end = mid - 1;
      }else{
        start = mid +1 ;
      }
    }
  }
public:
  void solution()
  {
    vector<int> arr = {3, 4, 13, 13, 13, 20, 40};
    int target = 13;
    int firstOccurence = -1,lastOccurence = -1;
    find_firstOccurence(arr,0,arr.size()-1,firstOccurence,target);
    find_lastOccurence(arr,0,arr.size()-1,lastOccurence,target);
    cout<<"First Occurence: "<<firstOccurence<<", Last Occurence: "<<lastOccurence<<"\n";
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