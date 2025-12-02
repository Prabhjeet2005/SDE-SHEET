#include <iostream>
#include <vector>
#include <unistd.h>
#include <chrono>
#include <iomanip>
#include <algorithm>

using namespace std;

/* --------------------------------------------------
                    KRUSKAL
 -------------------------------------------------- */

struct Edges
{
  int u, v, w;
};

bool static custom_compare(Edges a, Edges b)
{
  return a.w < b.w;
}

int find_parent(int node, vector<int> &parent)
{
  if (node == parent[node])
    return node;

  return parent[node] = find_parent(parent[node], parent);
}

void union_sets(int u, int v, vector<int> &parent)
{
  int rootU = find_parent(u, parent);
  int rootV = find_parent(v, parent);
  if (rootU != rootV)
  {
    parent[rootU] = rootV;
  }
}

int kruskal(vector<Edges> &edges, int V)
{
  sort(edges.begin(), edges.end(), custom_compare);

  int mst_sum = 0;
  vector<int> parent(V);
  for (int i = 0; i < V; i++)
    parent[i] = i;

  for (int i = 0; i < edges.size(); i++)
  {
    usleep(100);
    int u = edges[i].u;
    int v = edges[i].v;
    int w = edges[i].w;

    if (find_parent(u, parent) != find_parent(v, parent))
    {
      union_sets(u, v, parent);
      mst_sum += w;
      cout << "Edge " << u << " - " << v << " : " << w << "\n";
    }
  }

  return mst_sum;
}

int main()
{
  int V = 4;
  vector<Edges> edges;
  edges.push_back({0, 1, 1});
  edges.push_back({0, 2, 4});
  edges.push_back({1, 2, 2});
  edges.push_back({1, 3, 3});
  edges.push_back({2, 3, 5});
  auto start = chrono::high_resolution_clock::now();
  int mst = kruskal(edges, V);
  auto end = chrono::high_resolution_clock::now();

  chrono::duration<double> duration = end - start;

  cout << fixed << setprecision(3);
  cout << "MST Sum: " << mst << "\n";
  cout << duration.count() << "\n";
}