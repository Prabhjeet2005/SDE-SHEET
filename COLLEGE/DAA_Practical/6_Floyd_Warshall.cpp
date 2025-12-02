#include <iostream>
#include <vector>
#include <algorithm> // For min
#include <iomanip>   // For formatting

using namespace std;

/* --------------------------------------------------
                    FLOYD WARSHALL
 -------------------------------------------------- */

#define INF 99999 // Using a large number instead of INT_MAX to avoid overflow during addition

void floydWarshall(int V, vector<vector<int>> &matrix)
{
  // We work directly on the matrix

  // k = intermediate node
  for (int k = 0; k < V; k++)
  {
    // i = source node
    for (int i = 0; i < V; i++)
    {
      // j = destination node
      for (int j = 0; j < V; j++)
      {

        // If path i->k and k->j exist, check if it's shorter
        if (matrix[i][k] != INF && matrix[k][j] != INF)
        {
          matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
        }
      }
    }
  }

  // Print Logic
  cout << "Shortest distances between every pair of vertices:\n";
  for (int i = 0; i < V; i++)
  {
    for (int j = 0; j < V; j++)
    {
      if (matrix[i][j] == INF)
        cout << "INF" << "     ";
      else
        cout << matrix[i][j] << "     ";
    }
    cout << endl;
  }
}

int main()
{
  int V = 4;

  // Adjacency Matrix representation
  // Use INF for no direct connection
  vector<vector<int>> matrix = {
      {0, 5, INF, 10},
      {INF, 0, 3, INF},
      {INF, INF, 0, 1},
      {INF, INF, INF, 0}};

  floydWarshall(V, matrix);

  return 0;
}