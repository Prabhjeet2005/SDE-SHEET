#include <iostream>
#include <vector>
#include<math.h>

using namespace std;

class Solution
{
public:
  void solution() {
    vector<int> arr = {1,1,1,1,1,0,0,1,1,0,1,1,1,1,0};
    int currentOne =0;
    int maxOne = 0;

    for(int i=0; i<arr.size(); i++){
      if(arr[i] == 0){
        currentOne = 0;
        continue;
      }
      currentOne++;
      maxOne = max(currentOne,maxOne);
    }

    cout<<"Maximum Consecutive 1's: "<<maxOne<<endl;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}