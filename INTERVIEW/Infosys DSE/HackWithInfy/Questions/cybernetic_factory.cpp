/*
### ⚔️ Blind Story-Stripping Challenge 10

**Problem: The Cybernetic Factory**

You manage a massive automated factory that produces security drones for the Infosys campus. The factory has N different 3D-printing machines. You are given an array `time`, where `time[i]` is the exact number of seconds it takes the i-th machine to completely print 1 drone.

All N machines can run simultaneously (in parallel).

The company needs an emergency batch of exactly M drones. You want to power off the factory as soon as possible. Find the **minimum total time** (in seconds) required to print at least M drones.

**Constraints:**
1 <= N <= 10^5
1 <= M <= 10^9
1 <= time[i] <= 10^4

**Example Input & Output:**
* `time = [2, 3, 2]` (Machine 1 takes 2s, Machine 2 takes 3s, Machine 3 takes 2s)
* `M = 10` drones needed.

*If you guess the factory runs for `mid = 6` seconds:*
* Machine 1 produces: `6 / 2 = 3` drones.
* Machine 2 produces: `6 / 3 = 2` drones.
* Machine 3 produces: `6 / 2 = 3` drones.
* Total produced: `3 + 2 + 3 = 8` drones.
* *Result:* 8 < 10. INVALID.

**Expected Output:** `7`


*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
  void solution()
  {
    vector<int> arr = {2, 3, 2};
    int M = 10;

    int start = 1e9;
    long long end = 1e14; // START: Atleast 1 drone max amount time, END: 1 Machine all drones
    for (auto &element : arr)
    {
      start = min(start, element);
    }

    int min_time = -1;

    while (start <= end)
    {
      int mid = start + (end - start) / 2;
      if (is_valid(mid, M, arr))
      {
        min_time = mid;
        end = mid - 1; // Try earlier factory close
      }
      else
      {
        start = mid + 1;
      }
    }

    cout << "Min Time: " << min_time;
  }

private:
  bool is_valid(int mid, int M, vector<int> &arr)
  {
    int drones = 0;
    for (int i = 0; i < arr.size(); i++)
    {
      drones += floor(mid / arr[i]);
    }

    return drones >= M;
  }
};

int main()
{
  cout << endl;
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}