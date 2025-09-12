#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<string> strs = {"flower", "flow", "flight"};
    sort(strs.begin(),strs.end());
    string first = strs[0];
    string last = strs[strs.size()-1];

    string ans ="";
    for(int i=0; i<min(first.size(),last.size()); i++){
      if(first[i] != last[i]){
        break;
      }
      ans += first[i];
    }
    cout<<"Longest Common Prefix: "<<ans;
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