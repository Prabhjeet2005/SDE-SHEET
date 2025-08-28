#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    int ans = -1, start = 1, end = arr.size() - 2;
    if (arr[0] != arr[1])
    {
      ans = arr[0];
      
    }
    else if (arr[arr.size() - 1] != arr[arr.size() - 2])
    {
      ans = arr[arr.size() - 1];
      
    }
    else if (arr.size() == 1)
    {
      ans = arr[0];
      
    }

    if(ans!=-1){
      cout<<"Here";
      cout<<"Single Element: "<<ans;return;
    }

    while (start <= end)
    {
      int mid = start + (end - start) / 2;
      if ((arr[mid - 1] != arr[mid]) &&( arr[mid] != arr[mid + 1]))
      {
        ans = arr[mid];
        break;
      }
      if (((mid %2== 0) && arr[mid] == arr[mid + 1]) || ((mid %2== 1) && arr[mid] == arr[mid - 1]))
      {
        start = mid + 1;
      }
      else
      {
        end = mid - 1;
      }
    }

    cout << "Single Element: " << ans;
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