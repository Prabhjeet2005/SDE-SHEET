/*
### ⚔️ Blind Story-Stripping Challenge 8

**Problem: The Cyber Security Threat Analysts**

You are the lead of a cyber security response team at Infosys. The company server has recorded a sequence of N suspicious network logs over the last 24 hours. You are given an array `logs`, where `logs[i]` is the number of seconds it takes to analyze the i-th log.

You have exactly K security analysts available. To prevent mixing up timelines, you must assign **contiguous (adjacent)** segments of the logs to each analyst. Every log must be assigned to exactly one analyst.

Because the analysts work simultaneously, the total time to analyze all logs is determined by the analyst who gets the **heaviest workload** (the maximum sum of their assigned logs).

You want everyone to go home as early as possible. Find the **minimum possible maximum workload** you can give to any single analyst.

**Constraints:**
1 <= K <= N <= 10^5
1 <= logs[i] <= 10^4

**Example:**
* `logs = [10, 20, 30, 40]`
* `K = 2` analysts.
* If I guess `mid = 50`:
  * Analyst 1 takes `10`, then `20` (Total 30). `30 + 30 = 60`, which is > 50. So Analyst 1 stops at 30.
  * Analyst 2 takes `30`. `30 + 40 = 70` > 50. Analyst 2 stops at 30.
  * Analyst 3 is needed to take `40`.
  * *Result:* We needed 3 analysts, but we only have 2! Guess `50` **FAILED**. We need to guess a bigger workload limit.
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
    vector<int> logs = {10, 20, 30, 40};
    int K = 2;

    // START: Max of all logs atleast can take is time required atleast,
    // END: maximum all at once by 1 Analyst
    int start = 0, end = 0;
    for (auto &element : logs)
    {
      start = max(start, element); // FIX: Take max because process all logs
      end += element;
    }

    int min_possible_workload = 0;

    while (start <= end)
    {
      int mid = start + (end - start) / 2;
      if (is_valid(mid, K, logs))
      {
        min_possible_workload = mid;
        end = mid - 1; // If Valid Answer Try Reduce Load on Each
      }
      else
      {
        start = mid + 1;
      }
    }

    cout << "Min Possible Max Workload: " << min_possible_workload;
  }

private:
  bool is_valid(int mid, int K, vector<int> &logs)
  {
    int curr_load = 0;
    int curr_analysts = 1; // Atleast 1 analyst is required

    for (int i = 0; i < logs.size(); i++)
    {
      curr_load += logs[i];
      if (curr_load > mid) // FIX: Only Strictly greater
      {
        curr_analysts++;
        curr_load = logs[i]; // Make Next Analyst take current load
      }
    }
    return curr_analysts <= K;
  }
};

int main()
{
  cout << endl;
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}