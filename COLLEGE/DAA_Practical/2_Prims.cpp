#include <iostream>
#include <vector>
#include <chrono>
#include <unistd.h>
#include <iomanip>
#include <queue>
using namespace std;

/* --------------------------------------------------
                    PRIM
 -------------------------------------------------- */

struct customCompare
{
  bool operator()(pair<int, int> a, pair<int, int> b)
  {
    return a.second > b.second; // HEAP ULTA
  }
};

int prims_mst(vector<vector<pair<int, int>>> &adj, int V)
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, customCompare> pq;

  vector<bool> visited(V, false);

  int sum = 0;
  pq.push({0, 0});

  while (!pq.empty())
  {
    int node = pq.top().first;
    int weight = pq.top().second;
    pq.pop();

    if (visited[node])
      continue;

    visited[node] = true;
    sum += weight;

    for (auto &it : adj[node])
    {
      usleep(100);
      int adj_node = it.first;
      int adj_weight = it.second;
      if (!visited[adj_node])
      {
        pq.push({adj_node, adj_weight});
      }
    }
  }
  return sum;
}

int main()
{
  int V = 3;
  // {node,weight}
  vector<vector<pair<int, int>>> adj(V);
  adj[0].push_back({1, 5});
  adj[0].push_back({2, 1});
  adj[1].push_back({0, 5});
  adj[1].push_back({2, 3});
  adj[2].push_back({0, 1});
  adj[2].push_back({1, 3});

  auto start = chrono::high_resolution_clock::now();
  int mst_weight = prims_mst(adj, V);
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double> duration = end - start;

  cout << fixed << setprecision(3);
  cout << "MST Weight: " << mst_weight << "\n";
  cout << duration.count();
}