#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

class Solution
{
public:
  void insertion_sort() {
    vector<int> arr = {1, 5, 6, 2, 8, 3, 3};
    int n = arr.size();

    for(int i=0; i<n; i++){
      for(int j = i; j>0; j-- ){
        if(arr[j] < arr[j-1]){
          swap(arr[j],arr[j-1]);
        }else{
          break;
        }
      }
    }

    for(auto &it: arr){
      cout<<it<<", ";
    }
  }
};

int main()
{
  Solution sol = Solution();
  sol.insertion_sort();
  cout << endl;
}