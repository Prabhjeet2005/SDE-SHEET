#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {3, 4, 13, 13, 13, 20, 40};
    int target = 13;
    int firstOccurenece = -1,lastOccurence = -1;
    for(int i=0; i<arr.size();i++){
      if(arr[i]==target){
        firstOccurenece = i;
        break;
      }
    }
    for(int i=arr.size()-1; i>=0;i--){
      if(arr[i]==target){
        lastOccurence = i;
        break;
      }
    }
    cout<<"First Occurence: "<<firstOccurenece<<", Last Occurence: "<<lastOccurence<<"\n";
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