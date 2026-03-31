#include<iostream>
#include<vector>
using namespace std;

class SegmentTreeLazy{
  vector<int>arr;
  vector<int>tree;
  vector<int>lazy;
  int n;

  // Apply Previous changes to current node
  void push_down(int node,int start,int end){
    if(lazy[node] != 0){
      // Apply Pending Update of all child in range
      tree[node] += lazy[node] * (end-start+1);

      // Apply Update to Children if not Leaf Nodes
      if(start != end){
        int left_child = 2 * node + 1;
        int right_child = 2 * node + 2;
        lazy[left_child] += lazy[node];
        lazy[right_child] += lazy[node];
      }
      // Reset For any new Updates
      lazy[node] = 0;
    }
  }

  void build_segment_tree_lazy(int node,int start, int end){
    if(start == end){
      tree[node] = arr[start];
      return;
    }

    int mid = start + (end - start)/2;
    int left_child = 2 * node + 1;
    int right_child = 2 * node + 2;

    build_segment_tree_lazy(left_child,start,mid);
    build_segment_tree_lazy(right_child,mid+1,end);

    tree[node] = tree[left_child] + tree[right_child];
  }

  // UPDATE to range not point that is why 3 cases
  void update_segment_tree_lazy(int node,int start,int end,int L,int R,int value){
    // Apply previous Updates
    push_down(node,start,end);

    // Completely OUTSIDE
    if(start > R || end < L){
      return;
    }

    // Completely Inside
    if(start >= L && end <= R){
      tree[node] += value * (end - start + 1);

      if(start != end){
        int left_child = 2 * node + 1;
        int right_child = 2* node + 2;
        lazy[left_child] += value;
        lazy[right_child] += value;
      }
      return;
    }

    // Partially Inside
    int mid = start + (end - start)/2;
    int left_child = 2 * node + 1;
    int right_child = 2 * node + 2;

    update_segment_tree_lazy(left_child,start,mid,L,R,value);
    update_segment_tree_lazy(right_child,mid+1,end,L,R,value);

    tree[node] = tree[left_child] + tree[right_child];
  }

  int query_segment_tree_lazy(int node,int start,int end,int L,int R){
    push_down(node,start,end);

    if(start > R || end < L){
      return 0;
    }

    if(start >= L && end <= R){
      return tree[node];
    }

    // Partially Inside
    int mid = start + (end - start) / 2;
    int left_child = 2 * node + 1;
    int right_child = 2 * node + 2;

    int left_ans = query_segment_tree_lazy(left_child, start, mid, L, R);
    int right_ans = query_segment_tree_lazy(right_child, mid + 1, end, L, R);

    return left_ans + right_ans;
  }

  public:
  SegmentTreeLazy(vector<int>&input){
    n = input.size();
    arr = input;
    tree.resize(4*n,0);
    lazy.resize(4*n,0);
    build_segment_tree_lazy(0,0,n-1);
  }

  void update(int L,int R,int value){
    update_segment_tree_lazy(0,0,n-1,L,R,value);
  }

  int query(int L,int R){
    return query_segment_tree_lazy(0,0,n-1,L,R);
  }

};

int main(){
  vector<int> input_arr = {1, 3, 5, 7, 9};
  SegmentTreeLazy seg_tree = SegmentTreeLazy(input_arr);
  cout << "\n";

  // 1. Initial sum of range [1, 3] -> 3 + 5 + 7 = 15
  int initial_sum = seg_tree.query(1, 3);
  cout << "Initial Sum of range [1, 3] is: " << initial_sum << endl;

  // 2. Massive Surge: Add 10 to EVERY element from index 1 to 3
  // Array theoretically becomes: {1, 13, 15, 17, 9}
  seg_tree.update(1, 3, 10);
  cout << "Added 10 to all elements in range [1, 3]." << endl;

  // 3. New sum of range [1, 3] -> 13 + 15 + 17 = 45
  int new_sum = seg_tree.query(1, 3);
  cout << "New sum of range [1, 3] is: " << new_sum << endl;
  cout << "\n";
}