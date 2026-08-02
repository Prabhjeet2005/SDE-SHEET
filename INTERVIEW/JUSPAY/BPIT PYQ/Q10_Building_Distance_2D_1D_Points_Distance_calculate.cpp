/*
Building Distance Analysis
Problem Statement:
In a large city, buildings are arranged in a grid with n rows and m columns.
Each building in this grid has a specific building_
type represented by an integer from 1 to
100000.
City planners want to analyze the distance between all buildings of the same type to better
understand the distribution of building clusters.
The Manhattan distance between two buildings located at (r1, c1) and (r2, c2) is the total
number of horizontal and vertical steps required to reach one from the other.
The task is to calculate the sum of the Manhattan distances between each pair of buildings
of the same type for every unique building type in the grid.
Input:
First line contains two integers n and m
The next n lines each contain m integers representing the building types
Output:
Print a single integer representing the sum of Manhattan distances between each pair of
buildings of the same type.
Constraints:
1 <= n <= 10^5
1 <= m <= 10^5
1 <= a[i][j] <= 10^5
n × m <= 10^5
Sample Input:
2
3
1 2 3
3 2 1
Sample Output:
7
Sample Input:
3
4
1 1 2 2
2 1 1 2
2 2 1 1
Sample Output:
76
*/

#include <iostream>
#include <vector>
using namespace std;

long long get_1d_dist(vector<int>&arr){
  
  sort(arr.begin(),arr.end());
  vector<int>suff(arr.size(),0);
  
  suff[arr.size()-1] = arr[arr.size()-1];
  
  for(int i=arr.size()-2; i>=0; i--){
    suff[i] = suff[i+1]+arr[i];
  }
  // {2,4,6,8} -> (4-2)(6-2)(8-2) -> (4+6+8)-(2 * count_right)
  // Each Pair of Same Type so add all
  long long dist = 0;
  for(int i=0; i<arr.size()-1; i++){
    int count_right = arr.size() - i -1;
    dist += suff[i+1] - (arr[i] * count_right);
  }
  return dist;
}

int main()
{
  vector<vector<int>> grid = 
  {{1, 1, 2, 2}, {2, 1, 1, 2}, {2, 2, 1, 1}};

  int n = 3, m=4;
  vector<vector<int>>x(100000),y(100000);
  for(int row = 0; row < n; row++){
    for(int col = 0; col < m; col++){
      int building = grid[row][col];
      x[building].push_back(row);
      y[building].push_back(col);
    }
  }
  long long sum_manhattan = 0;

  for(int i=0; i<100000; i++){
    if(!x[i].empty()){
      sum_manhattan += get_1d_dist(x[i]);
    }
    if(!y[i].empty()){
      sum_manhattan += get_1d_dist(y[i]);
    }
  }

  cout<<sum_manhattan<<"\n";

}