#include <iostream>
#include <vector>
#include<unordered_map>

using namespace std;

class Solution
{
public:
  void solution() {
    vector<int> arr = {4,4,2,4,3,4,4,3,2,4};  

    unordered_map<int,int>map;

    for(int i=0; i<arr.size(); i++){
      map[arr[i]]++;
    }

    int majorityElement = 0;
    int count=0;
    for(auto &it:map){
      if(it.second > count){
        majorityElement = it.first;
      }
    }
    cout<<"Majority Element: "<<majorityElement<<endl;
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}