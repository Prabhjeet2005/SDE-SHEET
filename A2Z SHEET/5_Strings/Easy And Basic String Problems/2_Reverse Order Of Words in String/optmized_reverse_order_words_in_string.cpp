#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution
{
  void remove_space_left_right(string &str){
    int startNonSpace = 0;
    for(int i=0; i<str.size(); i++){
      if(str[i] != ' '){
        startNonSpace = i;break;
      }
    }
    str.erase(0,startNonSpace);
    int endNonSpace = str.size()-1;
    for(int i = str.size()-1; i>=0 ;i--){
      if(str[i] != ' '){
        endNonSpace = i;break;
      }
    }
    str.erase(endNonSpace+1,str.size()-endNonSpace-1);
    cout<<"Removed Space: "<<str<<"\n";
  }
public:
  void solution()
  {
    string str = "        This is decent       ";
    remove_space_left_right(str);
    int size = str.size();
    int left = size-1,right = size-1;
  string ans = "";
    while(left >= 0){
      char ch = str[left];
      if(ch == ' ' && left != size-1 ){
        ans += str.substr(left+1,right - (left + 1) + 1) + " ";
      }else if(ch != ' ' && left != size - 1 && str[left + 1] == ' '){
        right = left;
      }
      left--;
    }
    ans += str.substr(0,right+1);    
    cout << "Reversed Order String: " << ans;
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