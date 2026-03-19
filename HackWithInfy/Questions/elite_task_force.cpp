/*
### ⚔️ Blind Story-Stripping Challenge 13 (The Final Tree DP)

Let's test your theory about changing that single math line. This is a classic "Medium" level query problem.

 **Problem: The Elite Task Force**

 You are the general of an army structured as a hierarchy of N soldiers (rooted at the General, Node 0). Every soldier is connected to their direct reports via N-1 communication lines.

 Every soldier has a designated "Combat Power" level. You are given an array `power`, where `power[i]` is the combat power of the i-th soldier.

 You need to form specialized task forces. You receive Q queries. Each query gives you a soldier ID, U. When you select Soldier U to lead a task force, they will deploy with every single soldier in their entire down-line (their subtree).

 For each query U, you must return the **Maximum Combat Power** possessed by *any single soldier* within that task force (which means the maximum power in the subtree of U).

 **Constraints:**
 1 <= N <= 10^5
 1 <= Q <= 10^5
 1 <= power[i] <= 10^9

**INPUT:**
```text
5
3
100
500
200
900
50
0 1
0 2
1 3
1 4
0
1
2
```

**OUTPUT:**
```text
900
900
200
```

Here is the exact line-by-line structure of the input data:

* **Line 1:** A single integer $N$ (Total number of soldiers/nodes).
* **Line 2:** A single integer $Q$ (Total number of queries).
* **Next $N$ lines:** One integer per line representing the `power` array (the combat power of soldier $0$ through soldier $N-1$).
* **Next $N-1$ lines:** Two space-separated integers $u$ and $v$ per line, representing an undirected edge (communication line) between two soldiers.
* **Next $Q$ lines:** One integer per line representing the query $U$ (the soldier ID you need to find the maximum subtree power for).

*(Explanation: The max power in the whole army (node 0) is 900. The max power under node 1 is 900. The max power under node 2 is just 200).*
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
  vector<vector<int>> adj_list;
  vector<int> subtree;
  vector<int> values;

public:
  void solution(int N, int Q, vector<vector<int>> &edges, vector<int> &power, vector<int> &queries)
  {
    adj_list.resize(N + 1);
    subtree.resize(N + 1, 0);
    values = power;

    for (auto &edge : edges)
    {
      int u = edge[0], v = edge[1];
      adj_list[u].push_back(v);
      adj_list[v].push_back(u);
    }

    dfs(0, -1);

    vector<int> result(Q, 0);

    for (int i = 0; i < Q; i++)
    {
      int query = queries[i];
      result[i] = subtree[query]; // FIX: Correctly get result
    }
    cout << "Result:-\n";
    for (auto &element : result)
    {
      cout << element << "\n";
    }
  }

private:
  void dfs(int curr_node, int parent_node)
  {
    subtree[curr_node] = values[curr_node];
    for (auto &child : adj_list[curr_node])
    {
      if (child == parent_node)
        continue;
      dfs(child, curr_node);
      // Max out of curr or child_node soldier
      subtree[curr_node] = max(subtree[curr_node], subtree[child]);
    }
  }
};

int main()
{
  cout << endl;
  Solution sol = Solution();
  int N, Q;
  vector<vector<int>> edges;
  vector<int> power;
  vector<int> queries;
  cin >> N >> Q;
  for (int i = 0; i < N; i++)
  {
    int s;
    cin >> s;
    power.push_back(s);
  }
  for (int i = 0; i < N - 1; i++)
  {
    int u, v;
    cin >> u >> v;
    edges.push_back({u, v});
  }
  for (int i = 0; i < Q; i++)
  {
    int q;
    cin >> q;
    queries.push_back(q);
  }
  sol.solution(N, Q, edges, power, queries);
  cout << endl;
}