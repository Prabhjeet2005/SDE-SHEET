#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    int k = 2;
    string leftOrRight = "right";
    if (leftOrRight == "left")
    {
      vector<int> temp;
      for (int i = 0; i < k; i++)
      {
        temp.push_back(arr[i]);
      }
      arr.erase(arr.begin(), arr.begin() + k);
      for (int i = 0; i < temp.size(); i++)
      {
        arr.push_back(temp[i]);
      }
    }
    else
    {
      vector<int> temp;
      for (int i = arr.size() - k; i < arr.size(); i++)
      {
        temp.push_back(arr[i]);
      }
      arr.erase(arr.end() - k, arr.end());
      for (int i = temp.size() - 1; i >= 0; i--)
      {
        arr.insert(arr.begin(),temp[i]);
      }

    }

    for(auto &it:arr){
      cout<<it<<", ";
    }
  }
};

int main()
{
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}