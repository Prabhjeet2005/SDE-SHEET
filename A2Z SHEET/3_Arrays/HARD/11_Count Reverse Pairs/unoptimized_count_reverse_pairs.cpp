#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {1, 3, 2, 3, 1};
    int count = 0;
    for(int i=0; i<arr.size(); i++){
      for(int j=i+1; j<arr.size();j++){
        if(arr[i] > 2*arr[j])count++;
      }
    }
    cout <<"Count: "<<count<<"\n";
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