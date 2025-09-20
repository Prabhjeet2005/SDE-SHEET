#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
  void solution(vector<int> &arr)
  {
    int n = arr.size();
    vector<long long> prefix(n,0);
    prefix[0] = arr[0];
    for(int i=1;i<n;i++){
      prefix[i] = prefix[i-1]+arr[i];
    }

    for(int i=1;i<n-1;i++){
      for(int j=i+1;j<n;j++){
        long long sum1 = prefix[i-1];
        long long sum2 = prefix[j-1] - prefix[i-1];
        long long sum3 = prefix[n-1] - prefix[j-1];
        int  mod1 = sum1%3;
        int  mod2 = sum2%3;
        int  mod3 = sum3%3;
        bool same = (mod1 == mod2) && (mod1 == mod3);
        bool notSame = (mod1  != mod2 ) && (mod1 != mod3) && (mod2  != mod3);
        if(same || notSame){
          cout<<i<<" "<<j;return;
        }
      }
    }
    cout<<"0 0";
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