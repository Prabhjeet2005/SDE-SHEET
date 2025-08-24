#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
class Solution{
  public:
  void solution(){
    vector<int> arr = {3, 1, 2, 5, 4, 6, 7, 5};
    int n = arr.size();
    int missingNumber = -1, repeatingNumber = -1;

    for(int i=1; i<=n; i++){
      int count = 0;
      for(int j=0; j<n; j++){
        if(arr[j]==i)count++;
      }
      if(count == 0){
        missingNumber = i;
      }else if(count==2){
        repeatingNumber = i;
      }
      if(repeatingNumber != -1 && missingNumber != -1){
        break;
      }
    }

    cout<<"Missing Number: "<<missingNumber<<"\nRepeating Number: "<<repeatingNumber;
  }
};
int main(){
  cout<<"\n";
  Solution sol = Solution();
  sol.solution();
  cout<<"\n";
}