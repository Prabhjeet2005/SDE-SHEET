#include <iostream>
#include <vector>
#include<unordered_set>
using namespace std;

class Solution
{
public:
  void solution(vector<int> &arr)
  {
    long long MOD = 998244353; 
    int n = arr.size();
    unordered_set<int>set;
    int currentMax = 0;
    for(int i=0; i<n; i++){
      if(arr[i] > currentMax){
        set.insert(i);
        currentMax=arr[i];
      }
    }
    currentMax = 0;
    for(int i=n-1; i>=0; i--){
      if(arr[i] > currentMax){
        set.insert(i);
        currentMax=arr[i];
      }
    }
    int fillers = n-set.size();
    
    long  long ans=1;
    for(int i=1; i<=fillers;i++){
      ans = (ans * 2)%MOD;
    }
    cout<<ans;
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol = Solution();
  int testcases = 0;
  cin >> testcases;
  while (testcases > 0)
  {
    int n;
    vector<int> arr;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      int temp;
      cin >> temp;
      arr.push_back(temp);
    }
    sol.solution(arr);
    cout << "\n";
    testcases--;
  }
}