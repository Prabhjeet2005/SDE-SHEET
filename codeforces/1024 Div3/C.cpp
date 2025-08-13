#include <iostream>
#include <vector>
#include<math.h>

using namespace std;

class Solution
{
  bool change(int elementS,int elementT,int k){
    if(elementS + k == elementT || abs(elementS - k) == elementT){
      return true;
    }
    else{
      return false;
    }
  }
public:
  string solution(vector<int> &S, vector<int> &T,int k)
  {
    bool changePossible = true;
    for(int i=0; i<S.size(); i++){
      int elementS = S[i];
      int elementT = T[i];

      if(elementS != elementT){
        changePossible = change(elementS,elementT,k);
      }
      if(!changePossible){
        break;
      }
    }

    if(!changePossible){
      return "no";
    }
    return "yes";
  }
};

int main()
{
  Solution sol = Solution();
  vector<int>S;
  vector<int>T;
  int t;
  cin>>t;
  for(int j=0; j<t; j++){
    int n,k;
    cin>>n>>k;
    for(int i=0; i<n; i++){
      int element;
      cin>>element;
      S.push_back(element);
    }
    for(int i=0; i<n; i++){
      int element;
      cin>>element;
      T.push_back(element);
    }
    string ans = sol.solution(S,T,k);
    cout << ans;
  }
      
  cout << endl;
}