#include <iostream>
#include <vector>
#include <chrono>
#include <climits>
#include <iomanip>
#include <unistd.h>
using namespace std;

/* --------------------------------------------------
                    BELLMAN FORD
 -------------------------------------------------- */

struct Edges
{
  int u, v, w;
};

void bellman_ford(vector<Edges> &edges, int V, int src)
{
  vector<int> dist(V, INT_MAX);
  dist[src] = 0;

  for (int i = 0; i < V - 1; i++)
  {
    for (auto &edge : edges)
    {
      int u = edge.u;
      int v = edge.v;
      int w = edge.w;

      if (dist[u] != INT_MAX && dist[u] + w < dist[v])
      {
        dist[v] = dist[u] + w;
      }
    }
  }
  for (auto &edge : edges)
  {
    int u = edge.u;
    int v = edge.v;
    int w = edge.w;

    if (dist[u] != INT_MAX && dist[u] + w < dist[v])
    {
      cout << "\nNEGATIVE CYCLE DETECTED\n";
      return;
    }
  }

  for (int i = 0; i < dist.size(); i++)
  {
    cout << "Distance From SOURCE to " << i << " is: " << dist[i] << "\n";
  }
}

int main()
{
  int V = 5;
  vector<Edges> edges;
  edges.push_back({0, 1, -1});
  edges.push_back({0, 2, 4});
  edges.push_back({1, 2, 3});
  edges.push_back({1, 3, 2});
  edges.push_back({1, 4, 2});
  edges.push_back({3, 2, 5});
  edges.push_back({3, 1, 1});
  edges.push_back({4, 3, -3});

  auto start = chrono::high_resolution_clock::now();
  bellman_ford(edges, V, 0);
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double> duration = end - start;
  cout << fixed << setprecision(3);
  cout << "\n"
       << duration.count() << "\n";
}