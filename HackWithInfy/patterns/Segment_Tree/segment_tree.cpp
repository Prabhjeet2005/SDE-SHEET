#include<iostream>
#include<vector>

using namespace std;

class SegmentTree{
  vector<int>arr;
  vector<int>tree;
  int n;  
  
  void build_segment_tree(int node, int start, int end)
  {
    // Base Case
    if(start == end){
      tree[node] = arr[start]; // FIX: Access only Array elements and tree is 4*N
      return;
    }

    int mid = start + (end - start)/2;
    int left_child = 2 * node + 1;
    int right_child = 2 * node + 2;

    build_segment_tree(left_child, start, mid);
    build_segment_tree(right_child, mid + 1, end);

    // Each Parent only store Info for Children
    tree[node] = tree[left_child] + tree[right_child]; 
  }

  void update_segment_tree(int node, int start, int end, int index, int value){
    if(start == end){
      arr[index] = value;
      tree[node] = value;
      return;
    }

    int mid = start + (end - start)/2;
    int left_child = 2 * node + 1;
    int right_child = 2 * node + 2;

    if(index <= mid){
      update_segment_tree(left_child,start,mid,index,value);
    }else{
      update_segment_tree(right_child,mid+1,end,index,value);
    }

    tree[node] = tree[left_child] + tree[right_child];

  }

  int query_segment_tree(int node,int start,int end,int L,int R){
    // Case 1: Completely Outside [too Far LEFT and too Far RIGHT]
    if(start > R || end < L ){  // FIX: Either entire Left or Entire Right
      return 0;
    }

    // Case 2: Completely Inside
    if(L <= start && end <= R){
      return tree[node];
    }

    // Case 3: Partially Inside
    int mid = start + (end - start)/2;
    int left_child = 2 * node + 1;
    int right_child = 2* node + 2;

    int left_ans = query_segment_tree(left_child,start,mid,L,R);
    int right_ans = query_segment_tree(right_child,mid+1,end,L,R);

    return left_ans + right_ans;
    
  }

  public:
  
  SegmentTree(vector<int>&arr){
    this->arr = arr;
    n = arr.size();
    tree.resize(4*n,0);
    build_segment_tree(0,0,n-1);
  }

  void update(int index,int value){
    update_segment_tree(0,0,n-1,index,value);
  }

  int query(int L,int R){
    return query_segment_tree(0,0,n-1,L,R);
  }

};

int main(){
  vector<int>input_arr = {1,3,5,7,9};
  SegmentTree seg_tree = SegmentTree(input_arr);
  cout<<"\n";
  // 2. The King asks for the sum from index 1 to 3
  int initial_sum = seg_tree.query(1, 3);
  cout << "Sum of range [1, 3] is: " << initial_sum << endl;

  // 3. The Wizard updates index 2 to the value 10
  seg_tree.update(2, 10);
  cout << "Index 2 updated to 10." << endl;

  // 4. The King asks for the sum again
  int new_sum = seg_tree.query(1, 3);
  cout << "New sum of range [1, 3] is: " << new_sum << endl;
  cout<<"\n";
}