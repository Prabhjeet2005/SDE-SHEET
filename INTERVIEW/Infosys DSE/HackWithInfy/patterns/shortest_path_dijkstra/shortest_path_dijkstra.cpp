/*
***

### ⚔️ Blind Story-Stripping Challenge 14

Let's test this directly with a story inspired by the "Delivery Drone" problem in your Question Bank.

 **Problem: The Infosys Campus Delivery**

 You are programming an automated delivery drone for the massive Infosys campus. The campus has N buildings connected by M one-way aerial corridors.

 Each corridor has a specific battery cost to fly through. You are given an array of `corridors`, where `corridors[i] = [U, V, C]` means there is a one-way corridor from building U to building V that drains C units of battery.

 The drone starts at the Main Gate (Building 1) with a fully charged battery. The VIP client is waiting at the Executive Block (Building N).

 Find the **minimum battery cost** required to fly from Building 1 to Building N. If it is impossible to reach Building N, return `-1`.

 **Constraints:**
 2 <= N <= 10^5
 1 <= M <= 2 x 10^5
 1 <= C <= 1000

**INPUT FORMAT:**
```text
4 4
1 2 5
1 3 2
3 2 1
2 4 4
```
cheapest Path:  1 - 3 - 2 - 4.
Cost = 2 + 1 + 4 = 7*
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
  vector<vector<pair<int, int>>> adj_list; // {weight,node}
  vector<int> dist;
  // Min HEAP {distance,node}
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

public:
  void solution(int N, int M, vector<vector<int>> &corridors)
  {
    adj_list.resize(N + 1); // {weight,node}
    dist.resize(N + 1, 1e9);
    // Min HEAP {distance,node}

    for (auto &corridor : corridors)
    {
      int u = corridor[0], v = corridor[1], w = corridor[2];
      adj_list[u].push_back({w, v});
    }

    get_shortest_path();

    if (dist[N] == 1e9)
    {
      cout << "-1";
    }
    else
    {
      cout << dist[N];
    }
  }

  private:
  void get_shortest_path(){
    dist[1] = 0; // 1 Building Dist 0
    pq.push({0, 1});

    while (!pq.empty())
    {
      pair<int, int> top = pq.top();
      pq.pop();
      int curr_node = top.second;
      int curr_weight = top.first;

      // curr node check
      if (curr_weight > dist[curr_node])
        continue;

      for (auto &neighbor : adj_list[curr_node])
      {
        int neighbor_node = neighbor.second;
        int neighbor_weight = neighbor.first;

        if (curr_weight + neighbor_weight < dist[neighbor_node])
        {
          dist[neighbor_node] = curr_weight + neighbor_weight;
          pq.push({dist[neighbor_node], neighbor_node});
        }
      }
    }
  }
};

int main()
{
  Solution sol;
  int N = 4, M = 4;
  vector<vector<int>> corridors = {
      {1, 2, 5},
      {1, 3, 2},
      {3, 2, 1},
      {2, 4, 4}};
      cout<<"\n";
      sol.solution(N, M, corridors);
      cout<<"\n";
  return 0;
}
