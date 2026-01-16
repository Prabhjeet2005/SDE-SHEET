#include <iostream>
#include <vector>

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
    cout << "\n---Kahn's [Topological Sort]---\n";
    
    cout << "\n---DFS---\n";
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
    stack<int>s;
    s.push(curr_node);
    visited[curr_node] = true;

    while(!s.empty()){
      int top = s.top();
      s.pop();

      cout<<top<<", ";
      for(auto &neighbour:adj_list[top]){
        if(!visited[neighbour]){
          s.push(neighbour);
          visited[neighbour] = true;
        }
      }
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