/*

### ⚔️ Blind Story-Stripping Challenge 23 (The Hybrid)

No hints. Read the rules, figure out what to sort by, and figure out what goes in your heap.

 **Problem: The Cyber-Bounty Hunter**

 You are an elite bounty hunter on a space station. There are N targets available to capture. You are given two arrays of size N: `deadline` and `reward`.

 For the i-th target, you must capture them on or before day `deadline[i]`, otherwise they escape the station forever. If you successfully capture them, you earn `reward[i]` credits.

 **The Restriction:** It takes you exactly **1 full day** to track and capture a single target. You can only hunt one target at a time. You start at Day 0.

 Find the maximum total reward you can earn.

 **Constraints:**
 1 <= N <= 10^5
 1 <= deadline[i] <= 10^5
 1 <= reward[i] <= 10^9

**INPUT FORMAT:**
Line 1: N
Line 2: N integers representing `deadline`
Line 3: N integers representing `reward`

**Sample Input:**

5
2 1 2 1 3
100 19 27 25 15


**Sample Output:**

142

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

struct Bounty
{
  int deadline;
  int reward;
};

bool static custom_compare(Bounty a, Bounty b)
{
  return a.deadline < b.deadline;
}

struct CustomCompare
{
  bool operator()(Bounty a, Bounty b)
  {
    return a.reward > b.reward; // Min Heap
  }
};

class Solution
{
public:
  void solution()
  {
    int n = 5;
    long long total_reward = 0, curr_jobs = 0;
    vector<int> deadline = {2, 1, 2, 1, 3};
    vector<int> reward = {100, 19, 27, 25, 15};

    vector<Bounty> arr;
    for (int i = 0; i < n; i++)
    {
      arr.push_back({deadline[i], reward[i]});
    }

    // SORT by Deadline then if more than if more jobs than days then drop cheapest job
    sort(arr.begin(), arr.end(), custom_compare);
    priority_queue<Bounty, vector<Bounty>, CustomCompare> min_heap;

    // Take Mindlessly, if stuck then remove cheapest
    for (int i = 0; i < n; i++)
    {
      min_heap.push(arr[i]);
      total_reward += arr[i].reward;
      curr_jobs++;

      if (curr_jobs > arr[i].deadline)
      {
        Bounty cheapest_job = min_heap.top();
        min_heap.pop(); // Cheapest Job dropped
        curr_jobs--;
        total_reward -= cheapest_job.reward;
      }
    }
    cout << "Total reward: " << total_reward;
  }
};

int main()
{
  cout << endl;
  Solution sol = Solution();
  sol.solution();
  cout << endl;
}