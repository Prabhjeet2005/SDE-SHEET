#include <iostream>
#include <vector>
#include<unordered_map>

using namespace std;

class Solution
{
public:
  void solution() {
    vector<int>arr = {4,1,2,1,2};
    unordered_map<int,int>map;
    for(int i=0; i<arr.size(); i++){
      map[arr[i]]++;
    }

    for(auto &it: map){
      if(it.second == 1){
        cout<<"Single Occuring Element: "<<it.first<<endl;
      }
    }

  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}