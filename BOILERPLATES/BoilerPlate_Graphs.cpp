#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
  void solution()
  {
    int n = 5;
    vector<vector<int>> edges = {
        {0, 1}, {0, 4}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {3, 4}};
    // For Weighted graph {0,1,20} FORMAT: {u,v,w}

    vector<vector<int>> adj_list(n);
    create_adj_list(edges, adj_list); // GRAPH CREATION
    print_graph(adj_list);
    cout << "\n---BFS---\n";
    // for(int i=0; i<n; i++){  FOR DISCONNECTED COMPONENTS RUN A LOOP
    //   if(!visited[i]){
    bfs(adj_list, n);
    // }
    // }
    cout << "\n---DFS---\n";
    dfs(adj_list, n);

    cout << "\n---DFS USING STACK---\n";
    dfs_stack(adj_list, n);

    cout << "\n---Kahn's [Topological Sort] [Only On DAG]---\n";
    vector<vector<int>> edges_topo = {{0, 1}, {0, 2}, {1, 3}, {2, 3}};
    int n_topo = 4;
    vector<vector<int>> adj_list_topo(n_topo);
    create_adj_list_directed(edges_topo, adj_list_topo);
    topological_sort(adj_list_topo, n_topo);

    cout << "\n---Union-Find [Disjoint Set Union DSU]---\n";
    DSU dsu = DSU(5);
    dsu.union_nodes(1, 2);
    dsu.union_nodes(2, 3);
    if (dsu.find_parent(1) == dsu.find_parent(3))
    {
      cout << "Same Graph, Connceted Components\n";
    }
    else
    {
      cout << "Not Connected Graph";
    }
    if (dsu.find_parent(1) == dsu.find_parent(4))
    {
      cout << "Same Graph, Connceted Components";
    }
    else
    {
      cout << "Not Connected Graph";
    }

    cout << "\n---Dijkstra[Shortest Path from SOURCE]---\n";
    vector<vector<int>> edges_dijkstra = {
        {0, 1, 10},
        {1, 2, 20},
        {0, 3, 20},
        {3, 4, 30},
        {1, 4, 15},
        {3, 2, 10}};
    int n_dijkstra = 5;
    vector<vector<pair<int, int>>> adj_list_dijkstra(n_dijkstra + 1);
    create_adj_list_directed_weighted(adj_list_dijkstra, edges_dijkstra);
    dijkstra(adj_list_dijkstra, n_dijkstra);

    cout << "\n---BELLMAN FORD [-ve Cycle Detection & -ve Edge handle]---\n";
    int n_bellman = 3;
    vector<vector<int>> edges_bellman = {{0, 1, 20}, {0, 2, 10}, {1, 2, -15}};
    vector<vector<pair<int, int>>> adj_list_bellman(n_bellman + 1);
    create_adj_list_directed_weighted(adj_list_bellman, edges_bellman);
    bellman_ford(edges_bellman, n_bellman);

    cout << "\n---Floyd Warshal [All Pairs Shortest Path [Everywhere To Everywhere]]---\n";
    vector<vector<int>> edges_floyd = {
        {0, 1, 10},
        {0, 2, 20},
        {1, 2, 5},
        {2, 1, 7}};
    int n_floyd = 3;
    floyd_warshall(edges_floyd, n_floyd);

    cout << "\n---PRIMS [MST] [Similar Dijkstra]---\n";
    vector<vector<int>> edges_prims = {
        {0, 1, 10},
        {0, 3, 20},
        {0, 2, 7},
        {1, 2, 1},
        {1, 3, 5},
        {2, 3, 2}};
    int n_prims = 4;
    vector<vector<pair<int, int>>> adj_list_prims(n_prims + 1);
    create_adj_list_undirected(edges_prims, adj_list_prims);
    prims_mst(adj_list_prims, n_prims);

    cout
        << "\n---KRUSKAL MST [EDGE BASED for sparse Graphs -> Less edges]---\n";
    vector<vector<int>> edges_kruskal = {
        {0, 1, 10},
        {0, 3, 20},
        {0, 2, 7},
        {1, 2, 1},
        {1, 3, 5},
        {2, 3, 2}};
    int n_kruskal = 4;
    kruskal_mst(edges_kruskal, n_kruskal);

    cout << "\n---ADVANCED ALGORITHMS---\n";
    cout << "\n---BIPARTITE [Only 2 Colored Graph]---\n";
    vector<vector<int>> edges_bipartite = {{0, 1}, {1, 2}, {2, 3}, {0, 3}, {4, 5}};
    int n_bipartite = 6;
    vector<vector<int>> adj_list_bipartite(n_bipartite + 1);
    create_adj_list(edges_bipartite, adj_list_bipartite);
    bipartite(adj_list_bipartite, n_bipartite);

    cout << "\n---Tarjan's Algorithm [Bridges V.Imp & V.Hard]---\n";
    vector<vector<int>> edges_tarjan = {{0, 1}, {1, 2}, {2, 0}, {3, 0}};
    int n_tarjan = 4;
    vector<vector<int>> adj_list_tarjan(n_tarjan + 1);
    create_adj_list(edges_tarjan, adj_list_tarjan);
    tarjan_bridges(adj_list_tarjan, n_tarjan);

    cout << "\n---Articulation Points [Similar tarjan]---\n";
    adj_list_tarjan.clear();

    edges_tarjan = {{0, 1}, {1, 2}, {2, 0}, {3, 0}};
    n_tarjan = 4;
    adj_list_tarjan.resize(n_tarjan + 1);
    create_adj_list(edges_tarjan, adj_list_tarjan);
    tarjan_articulation_points(adj_list_tarjan, n_tarjan);
    cout << "\n---DFS---\n";
    cout << "\n---DFS---\n";
    cout << "\n---DFS---\n";
  }

private:
  void create_adj_list(vector<vector<int>> &edges, vector<vector<int>> &adj_list)
  {
    for (auto &edge : edges)
    {
      int u = edge[0];
      int v = edge[1];
      adj_list[u].push_back(v);
      adj_list[v].push_back(u);
    }
  }

  void create_adj_list_directed(vector<vector<int>> &edges_directed, vector<vector<int>> &adj_list_topo)
  {
    for (auto &edge : edges_directed)
    {
      int u = edge[0];
      int v = edge[1];

      adj_list_topo[u].push_back(v);
    }

    // print_graph(adj_list_topo);
  }

  void create_adj_list_directed_weighted(vector<vector<pair<int, int>>> &adj_list, vector<vector<int>> &edges)
  {
    for (auto &edge : edges)
    {
      int u = edge[0], v = edge[1], w = edge[2];
      adj_list[u].push_back({v, w});
    }
  }

  void create_adj_list_undirected(vector<vector<int>> &edges, vector<vector<pair<int, int>>> &adj_list)
  {
    for (auto &edge : edges)
    {
      int u = edge[0], v = edge[1], w = edge[2];
      adj_list[u].push_back({v, w});
      adj_list[v].push_back({u, w});
    }
  }

  void print_graph(vector<vector<int>> &adj_list)
  {
    for (int i = 0; i < adj_list.size(); i++)
    {
      cout << i << " is associated to :";
      for (int element : adj_list[i])
      {
        cout << element << ",";
      }
      cout << "\n";
    }
  }

  void bfs(vector<vector<int>> &adj_list, int n)
  {
    vector<bool> visited(n, false);
    if (n == 0)
      return;
    queue<int> q;

    q.push(0);
    visited[0] = true;
    while (!q.empty())
    {
      int front = q.front();
      q.pop();
      cout << front << ", ";
      for (auto &neighbour : adj_list[front])
      {
        if (!visited[neighbour])
        {
          q.push(neighbour);
          visited[neighbour] = true;
        }
      }
    }
  }

  void dfs(vector<vector<int>> &adj_list, int n)
  {
    vector<bool> visited(n, false);
    // For Disconnected Components, Run a Loop
    for (int i = 0; i < n; i++)
    {
      if (!visited[i])
      {
        dfs_helper(i, adj_list, visited, n);
      }
    }
  }

  void dfs_helper(int curr_node, vector<vector<int>> &adj_list, vector<bool> &visited, int n)
  {
    // Mark visited ASAP
    visited[curr_node] = true;
    // Process it
    cout << curr_node << ", ";
    // Recurse it
    for (auto &neighbour : adj_list[curr_node])
    {
      if (!visited[neighbour])
      {
        dfs_helper(neighbour, adj_list, visited, n);
      }
    }
  }

  void dfs_stack(vector<vector<int>> &adj_list, int n)
  {
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
      if (!visited[i])
      {
        dfs_stack_iterative(i, adj_list, n, visited);
      }
    }
  }

  void dfs_stack_iterative(int curr_node, vector<vector<int>> &adj_list, int n,
                           vector<bool> &visited)
  {
    stack<int> s;
    s.push(curr_node);
    visited[curr_node] = true;

    while (!s.empty())
    {
      int top = s.top();
      s.pop();

      cout << top << ", ";
      for (auto &neighbour : adj_list[top])
      {
        if (!visited[neighbour])
        {
          s.push(neighbour);
          visited[neighbour] = true;
        }
      }
    }
  }

  void topological_sort(vector<vector<int>> &adj_list, int n)
  {
    vector<int> indegree(n, 0);
    // Step 1. Calculate Indegree
    for (int i = 0; i < n; i++)
    {
      for (auto &neighbour : adj_list[i])
      {
        indegree[neighbour]++;
      }
    }

    queue<int> q;
    // Step 2. Indegree 0 push onto Queue
    for (int i = 0; i < n; i++)
    {
      if (indegree[i] == 0)
      {
        q.push(i);
      }
    }

    vector<int> topo_order;
    // Step3. Perform BFS
    while (!q.empty())
    {
      int front = q.front();
      q.pop();

      topo_order.push_back(front);

      for (auto &neighbour : adj_list[front])
      {
        indegree[neighbour]--;
        if (indegree[neighbour] == 0)
        {
          q.push(neighbour);
        }
      }
    }
    // Step 4. Cyclic Check
    if (topo_order.size() != n)
    {
      cout << "Topo Sort Not Possible, Cycle Present";
      return;
    }
    cout << "Topo Order: ";
    for (auto &element : topo_order)
    {
      cout << element << ", ";
    }
  }

  class DSU
  {
    vector<int> parent;
    vector<int> rank;

  public:
    DSU(int n)
    {
      parent.resize(n + 1);
      rank.resize(n + 1, 0);
      for (int i = 0; i <= n; i++)
      {
        parent[i] = i;
      }
    }

    int find_parent(int node)
    {
      if (node == parent[node])
        return node;

      return parent[node] = find_parent(parent[node]);
    }

    void union_nodes(int u, int v)
    {
      int parent_u = find_parent(u);
      int parent_v = find_parent(v);

      // CRITICAL: Same Graph Early Return
      if (parent_u == parent_v)
        return;

      // Attatch small -> Big
      if (rank[parent_u] < rank[parent_v])
      {
        parent[parent_u] = parent_v;
      }
      else if (rank[parent_u] > rank[parent_v])
      {
        parent[parent_v] = parent_u;
      }
      else
      {
        // Ranks Equal
        parent[parent_u] = parent_v;
        rank[parent_v]++;
        // Rank increase by 1 because same height and when connect to Root of Graph, Total Height of Graph becomes +1
      }
    }
  };

  struct CustomCompare
  {
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
      return a.second > b.second;
    }
  };

  void dijkstra(vector<vector<pair<int, int>>> &adj_list_dijkstra, int n)
  {
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, CustomCompare> pq;
    int source = 0;
    dist[source] = 0;
    // {v,w}
    pq.push({source, 0});

    while (!pq.empty())
    {
      pair<int, int> top = pq.top();
      int v = top.first;
      int w = top.second;
      pq.pop();

      // CRITICAL: If distance is older and smaller distance for node already exist then skip past it
      if (w > dist[v])
        continue;

      for (auto &neighbour : adj_list_dijkstra[v])
      {
        int dest_v = neighbour.first;
        int dest_w = neighbour.second;
        // Relaxing Edge (Updating An Edge Also Called Relaxing An Edge)
        if (dist[v] + dest_w < dist[dest_v])
        {
          dist[dest_v] = dist[v] + dest_w;
          pq.push({dest_v, dist[dest_v]});
        }
      }
    }

    cout << "Dist From Source: ";
    for (auto &d : dist)
    {
      cout << d << ", ";
    }
  }

  void bellman_ford(vector<vector<int>> &edges, int n)
  {
    vector<int> dist(n + 1, INT_MAX);
    int source = 0;
    dist[source] = 0;

    for (int i = 0; i < n - 1; i++)
    {
      for (auto &edge : edges)
      {
        int u = edge[0], v = edge[1], w = edge[2];

        // Update Edge [Relax Edge] if it has been visited
        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
          dist[v] = dist[u] + w;
        }
      }
    }

    // Relax 1 More Time
    for (auto &edge : edges)
    {
      int u = edge[0], v = edge[1], w = edge[2];

      // Update Edge [Relax Edge] if it has been visited
      if (dist[u] != INT_MAX && dist[u] + w < dist[v])
      {
        cout << "-ve Cycle Present";
        return;
      }
    }

    cout << "Distance: ";
    for (auto &element : dist)
    {
      cout << element << ", ";
    }
  }

  void floyd_warshall(vector<vector<int>> &edges, int n)
  {

    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    // LOAD Initial Weights
    for (auto &edge : edges)
    {
      int u = edge[0], v = edge[1], w = edge[2];
      dist[u][v] = w;
    }

    for (int i = 0; i < n; i++)
      dist[i][i] = 0;

    for (int k = 0; k < n; k++)
    {
      for (int i = 0; i < n; i++)
      {
        for (int j = 0; j < n; j++)
        {
          if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
          {
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
          }
        }
      }
    }

    // -ve CYCLE CHECK
    for (int i = 0; i < n; i++)
    {
      if (dist[i][i] < 0)
      {
        cout << "-ve CYCLE PRESENT";
        return;
      }
    }

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (dist[i][j] == INT_MAX)
        {
          cout << "INF ";
        }
        else
        {
          cout << dist[i][j] << " ";
        }
      }
      cout << "\n";
    }
  }

  void prims_mst(vector<vector<pair<int, int>>> &adj_list, int n)
  {
    priority_queue<pair<int, int>, vector<pair<int, int>>, CustomCompare> pq;
    vector<bool> visited(n + 1, false);
    int mst_sum = 0;
    // {v,w}
    pq.push({0, 0});

    while (!pq.empty())
    {
      pair<int, int> top = pq.top();
      int node = top.first;
      int weight = top.second;
      pq.pop();

      if (visited[node])
        continue;
      mst_sum += weight;
      visited[node] = true;

      for (auto &neighbours : adj_list[node])
      {
        int neighbour_node = neighbours.first;
        int neighbour_weight = neighbours.second;
        if (!visited[neighbour_node])
        {
          pq.push({neighbour_node, neighbour_weight});
        }
      }
    }
    cout << "Prims MST Sum: " << mst_sum;
  }

  bool static custom_compare(vector<int> &a, vector<int> &b)
  {
    return a[2] < b[2];
  }

  void kruskal_mst(vector<vector<int>> edges, int n)
  {
    sort(edges.begin(), edges.end(), custom_compare);

    DSU dsu = DSU(n);
    int mst_sum = 0;
    int edges_count = 0;

    for (auto &edge : edges)
    {
      int u = edge[0], v = edge[1], w = edge[2];
      if (dsu.find_parent(u) != dsu.find_parent(v))
      {
        dsu.union_nodes(u, v);
        edges_count++;
        mst_sum += w;
      }
    }
    //  Disconnected Graph Check
    if (edges_count != n - 1)
    {
      cout << "Graph is disconnected";
      return;
    }

    cout << "MST SUM KRUSKAL: " << mst_sum;
  }

  void bipartite(vector<vector<int>> &adj_list, int n)
  {
    vector<int> color(n + 1, -1); // -1 -> Uninitialized, 0 -> color_1, 1 -> color_2

    for (int i = 0; i <= n; i++)
    {
      if (color[i] == -1)
      {
        if (!check_bipartite(i, adj_list, color, n))
        {
          cout << "Not Bipartite";
          return;
        }
      }
    }
    cout << "Graph is Bipartite";
  }

  bool check_bipartite(int start_node, vector<vector<int>> &adj_list, vector<int> &color, int n)
  {
    queue<int> q;
    color[start_node] = 0;
    q.push(start_node);

    while (!q.empty())
    {
      int front = q.front();
      q.pop();

      for (auto &neighbour : adj_list[front])
      {
        if (color[neighbour] == -1)
        {
          color[neighbour] = !color[front];
          q.push(neighbour);
        }
        else if (color[neighbour] == color[front])
        {
          return false;
        }
      }
    }
    return true;
  }

  void tarjan_bridges(vector<vector<int>> &adj_list, int n)
  {
    vector<int> low(n + 1, 0);
    vector<int> tin(n + 1, 0);
    int timer = 1;
    vector<bool> visited(n + 1, false);
    vector<vector<int>> bridges;
    for (int i = 0; i < n; i++)
    {
      if (!visited[i])
      {
        // Don't visit Parent && DO DFS
        get_tarjan_bridges_dfs(i, -1, low, tin, timer, visited, bridges, adj_list);
      }
    }

    for (auto &bridge : bridges)
    {
      cout << bridge[0] << "-" << bridge[1];
      cout << "\n";
    }
  }

  void get_tarjan_bridges_dfs(int curr_node, int parent, vector<int> &low, vector<int> &tin, int &timer, vector<bool> &visited, vector<vector<int>> &bridges, vector<vector<int>> &adj_list)
  {
    visited[curr_node] = true;
    low[curr_node] = timer;
    tin[curr_node] = timer;
    timer++;

    for (auto &neighbour : adj_list[curr_node])
    {
      // Don't Go up and Visit the Parent
      if (neighbour == parent)
        continue;
      if (!visited[neighbour])
      {
        get_tarjan_bridges_dfs(neighbour, curr_node, low, tin, timer, visited, bridges, adj_list);

        low[curr_node] = min(low[curr_node], low[neighbour]);

        // BRIDGE CHECK if neighbour below the curr_node
        // Bridge only when the neighbour can't reach me back or ancestors
        if (low[neighbour] > tin[curr_node])
        {
          bridges.push_back({curr_node, neighbour});
        }
      }
      else
      {
        // Back Edge
        low[curr_node] = min(low[curr_node], tin[neighbour]);
      }
    }
  }

  void tarjan_articulation_points(vector<vector<int>> &adj_list, int n)
  {
    // Mark Articulation Points Instead of .push_back() because if suppose 3 branches to same node then each branch give curr_node as Articulation Point
    // We pushed back in Bridges because each Bridge Was Unique
    vector<bool> articulation_points(n + 1, 0);
    vector<int> low(n + 1, 0);
    vector<int> tin(n + 1, 0);
    vector<bool> visited(n + 1, false);
    int timer = 1;

    for (int i = 0; i < n; i++)
    {
      if (!visited[i])
      {
        // Send Parent As -1
        tarjan_articulation_points_dfs(i, -1, adj_list, articulation_points, low, tin, visited, timer);
      }
    }

    cout << "Articulation Points: ";
    for (int i = 0; i < articulation_points.size(); i++)
    {
      if (articulation_points[i])
      {
        cout << i << ", ";
      }
    }
  }

  void tarjan_articulation_points_dfs(int curr_node, int parent, vector<vector<int>> &adj_list, vector<bool> &articulation_points, vector<int> &low, vector<int> &tin, vector<bool> &visited, int &timer)
  {
    visited[curr_node] = true;
    low[curr_node] = timer;
    tin[curr_node] = timer;
    timer++;
    int children = 0;

    for (auto &neighbour : adj_list[curr_node])
    {
      // Ignore The parent Edge
      if (neighbour == parent)
        continue;
      if (!visited[neighbour])
      {
        children++; // Only Unvisited children
        tarjan_articulation_points_dfs(neighbour, curr_node, adj_list, articulation_points, low, tin, visited, timer);

        low[curr_node] = min(low[curr_node], low[neighbour]);

        // It can Reach to curr_node or Lower then only removing curr_node will make it Disconnected
        if (low[neighbour] >= tin[curr_node] && parent != -1)
        { // Ignore Root
          // curr_node is Articulation Point
          articulation_points[curr_node] = true;
        }
      }
      else
      {
        // Back edge
        low[curr_node] = min(low[curr_node], tin[neighbour]);
      }
    }

    // If Root has More than 1 children then only it will be an Articulation Point
    // If Root has 1 child then remove it the rest of graph is still connected, but my code will wrongly give root as Articulation Point
    if (children > 1 && parent == -1)
    {
      articulation_points[curr_node] = true;
    }
  }
};

int main()
{
  Solution sol = Solution();
  cout << "\n";
  sol.solution();
  cout << "\n";
}