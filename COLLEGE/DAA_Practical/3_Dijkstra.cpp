#include <iostream>
#include <vector>
#include <chrono>
#include <queue>
#include <unistd.h>
#include <iomanip>
using namespace std;

/* --------------------------------------------------
                    DIJKSTRA
 -------------------------------------------------- */

struct customCompare
{
  bool operator()(pair<int, int> a, pair<int, int> b)
  {
    return a.second > b.second;
  }
};

void dijkstra(vector<vector<pair<int, int>>> &adj, int V, int src)
{
  // Min Heap
  priority_queue<pair<int, int>, vector<pair<int, int>>, customCompare> pq;

  vector<int> dist(V, INT_MAX);
  dist[src] = 0;
  pq.push({src, 0});

  while (!pq.empty())
  {
    int node = pq.top().first;
    int weight = pq.top().second;
    pq.pop();

    if (weight > dist[node])
      continue;

    for (auto &it : adj[node])
    {
      usleep(100);
      int adj_node = it.first;
      int adj_weight = it.second;

      if (dist[node] + adj_weight < dist[adj_node])
      {
        dist[adj_node] = dist[node] + adj_weight;
        pq.push({adj_node, dist[adj_node]});
      }
    }
  }

  for (int i = 0; i < V; i++)
  {
    cout << "Node " << i << " : " << dist[i] << "\n";
  }
}

int main()
{
  int V = 3;
  vector<vector<pair<int, int>>> adj(V);

  adj[0].push_back({1, 5});
  adj[0].push_back({2, 1});
  adj[1].push_back({0, 5});
  adj[1].push_back({2, 3});
  adj[2].push_back({0, 1});
  adj[2].push_back({1, 3});

  auto start = chrono::high_resolution_clock::now();
  dijkstra(adj, V, 0);
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double> duration = end - start;

  cout << fixed << setprecision(3);
  cout << "\n"
       << duration.count() << "\n";
}