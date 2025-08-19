#include <iostream>
#include <vector>

using namespace std;

class Solution
{

public:
  void solution()
  {
    vector<vector<int>> arr = {{0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5}};

    bool row0 = 0, col0 = 0;
    for (int i = 0; i < arr.size(); i++)
    {
      if (arr[i][0] == 0)
      {
        col0 = true;
        break;
      }
    }

    for (int i = 0; i < arr[0].size(); i++)
    {
      if (arr[0][i] == 0)
      {
        row0 = true;
        break;
      }
    }

    for (int i = 1; i < arr.size(); i++)
    {
      for (int j = 1; j < arr[0].size(); j++)
      {
        if (arr[i][j] == 0)
        {
          arr[0][j] = 0;
          arr[i][0] = 0;
        }
      }
    }
    for (int i = 1; i < arr.size(); i++)
    {
      if(arr[i][0] == 0){
        for(int j = 1; j<arr[0].size();j++){
          arr[i][j] = 0;
        }
      }
    }
    for (int i = 1; i < arr[0].size(); i++)
    {
      if(arr[0][i] == 0){
        for(int j = 0; j<arr.size();j++){
          arr[j][i] = 0;
        }
      }
    }
    if(row0){
      for(int i=0; i<arr[0].size(); i++){
        arr[0][i] = 0;
      }
    }
    if(col0){
      for(int i=0; i<arr.size(); i++){
        arr[i][0] = 0;
      }
    }
    for (int i = 0; i < arr.size(); i++)
    {
      for (int j = 0; j < arr[0].size(); j++)
      {
        cout << arr[i][j] << ", ";
      }
      cout << endl;
    }
  }
};

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}