#include<iostream>
#include<string>
using namespace std;
class Solution
{
public:
  string largestOddNumber()
  { string num = "563018";
    int indexOdd = -1;
    for (int i = num.size() - 1; i >= 0; i--)
    {
      char ch = num[i];
      int currentDigit = stoi(to_string(ch));
      if (currentDigit % 2 == 1)
      {
        return num.substr(0, i + 1);
      }
    }
    return "";
  }
};

int main(){
  Solution sol = Solution();
  cout<<"\n";
  cout<< sol.largestOddNumber();
  cout<<"\n";
}