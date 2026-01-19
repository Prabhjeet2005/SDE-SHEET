
#include<iostream>
#include<vector>
class DSU{
  vector<int>parent;
  vector<int>rank;
  public:
  DSU(int n){
    parent.resize(n+1);
    rank.resize(n+1,0);
  }

  int find_parent(int node){
    if(node == parent[node])return node;
    return parent[node] = find_parent(parent[node]);
  }

  void union_nodes(int u, int v){
    int parent_u = find_parent(u);
    int parent_v = find_parent(v);

    if(parent_u == parent_v)return;

    if(rank[parent_u] < rank[parent_v]){
      parent[parent_u] = parent_v;
    }else if(rank[parent_u] > rank[parent_v]){
      parent[parent_v] = parent_u;
    }else{
      // Rank Same Increase Parent Rank by 1
      parent[parent_u] = parent_v;
      rank[parent_v]++;
    }
  }

};
