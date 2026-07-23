/*
Maximum Weight Node
Problem Statement:
The task is to find the cell with maximum weight.
The weight of a cell is defined as the sum of the indices of all cells pointing to that cell.
If there are multiple cells with the same maximum weight, return the cell with the highest
index.
Note:
Cells are indexed from 0 to N-1.
If no cell points to the ith cell, then its weight is 0.
Input Format:
First line contains an integer N.
Second line contains N integers representing the array edge[].
edge[i] contains the cell number that can be reached from cell i in one step.
edge[i] = -1 means the ith cell has no outgoing edge.

Output Format:
Print the node number having maximum weight.
Sample Input:
23
4 4 1 4 13 8 8 8 0 8 14 9 15 11 -1 10 15 22 22 22 22 22 21
Sample Output:
22
Sample Input:
7
4 4 -1 2 2 3 4
Sample Output:
4
*/

#include<iostream>
#include<vector>
using namespace std;

int get_max_weight_node(vector<int>&edge){
  int n = edge.size();
  vector<int>weight_sum(n,0);

  for(int i=0; i<n; i++){
    if(edge[i]==-1)continue;
    weight_sum[edge[i]] += i; // FIX: add index
  }

  int max_weight_node_idx = -1;
  int max_weight = -1e9;

  for(int i=0; i<n; i++){
    if(weight_sum[i] >= max_weight){
      max_weight_node_idx = i; 
      max_weight = weight_sum[i];
    }
  }

  return max_weight_node_idx;
}

int main(){
  vector<int>arr = {4,4,-1,2,2,3,4};
  int ans = get_max_weight_node(arr);
  cout<<ans<<endl;
}