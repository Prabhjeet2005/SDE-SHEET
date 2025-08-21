#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

class Solution
{
  void mergeSort(vector<int> &arr, int low, int mid, int high)
  {
    vector<int> ans;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
      if (arr[left] < arr[right])
      {
        ans.push_back(arr[left++]);
      }
      else
      {
        ans.push_back(arr[right++]);
      }
    }
    while (left <= mid)
    {
      ans.push_back(arr[left++]);
    }
    while (right <= high)
    {
      ans.push_back(arr[right++]);
    }

    for (int i = low; i <= high; i++)
    {
      arr[i] = ans[i - low];
    }
  }

  void sort(vector<int> &arr, int start, int end)
  {
    if (start >= end)
    {
      return;
    }
    int mid = start + (end - start) / 2;
    sort(arr, start, mid);
    sort(arr, mid + 1, end);
    mergeSort(arr, start, mid, end);
  }

public:
  void solution()
  {
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    int target = 0;
    vector<vector<int>> ans;

    sort(arr, 0, arr.size() - 1);

    for (int i = 0; i < arr.size() - 2; i++)
    {
      int j = i + 1, k = arr.size() - 1;
      if (i != 0 && arr[i] == arr[i - 1])
      {
        continue; // Skip Duplicates
      }
      while (j < k)
      {
        if (arr[i] + arr[j] + arr[k] == target)
        {
          vector<int> tempArr = {arr[i], arr[j], arr[k]};
          sort(tempArr, 0, tempArr.size() - 1);
          ans.push_back(tempArr);
          j++;k--;
          while(j<k && arr[j-1]==arr[j])j++;
          while(j<k && arr[k+1]==arr[k])k--;
        }
        else if (arr[i] + arr[j] + arr[k] > target)
        {
          k--;
        }
        else if (arr[i] + arr[j] + arr[k] < target)
        {
          j++;
        }
      }
    }

    for (auto &it : ans)
    {
      cout << "{";
      for (auto &element : it)
      {
        cout << element << ", ";
      }
      cout << "}, ";
    }
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