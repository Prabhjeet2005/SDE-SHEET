#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  void solution(int n,int c,int k,vector<int>&monster_attack){
    sort(monster_attack.begin(),monster_attack.end());
    long long ans=c;
    for(int i=0; i<monster_attack.size(); i++){
      int a = monster_attack[i];
      if(ans < a)break;
      int limit = ans-a;
      int flipflops = 0;

      if(k >= limit){
        ans+= a + limit;
        k-=limit;
      }else{
        if(k>0){
          // USE ALL Remaining flipflop
          ans+=k;
          k=0;
        }
        ans += a;
      }
    }
    cout<< ans;
  }
  
};

int main()
{
  int t;
  cin>>t;
  cout<<"\n\n OUTPUT\n\n";
  Solution sol = Solution();
  for(int i=0; i<t; i++){
    int n, c, k;
    cin >>n>>c>>k;
    vector<int>monster_attack_power;
    for(int i=0; i<n; i++){
      int a;
      cin>>a;
      monster_attack_power.push_back(a);
    }
    sol.solution(n,c,k,monster_attack_power);
    cout << endl;
  }
}