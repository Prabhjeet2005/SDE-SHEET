#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
  void solution()
  {
    MinHeap min_heap = MinHeap();
    // TC: O(NlogN) , Individual Push
    // min_heap.push(30);
    // min_heap.push(10);
    // min_heap.push(40);
    // min_heap.push(20);

    vector<int>arr = {40,30,20,10,6,70,90};
    // Heapify TC:O(N)
    // Here directly push Non-leaf Nodes to 0 and rest are already heapifyed
    min_heap.build_heap(arr);
    cout<<"TOP: ";
    cout<<min_heap.top()<<"\n";
    min_heap.pop();
    cout << "TOP: ";
    cout << min_heap.top() << "\n";

    vector<int>array = {20,10,50,60,30};
    MaxHeap max_heap = MaxHeap();
    max_heap.heap_sort(array);
    cout<<"\nSorted Arr [Using Max Heap]: ";
    for(auto &element:array){
      cout<<element<<", ";
    }
  }

private:
  class MinHeap
  {
    vector<int> heap;
    int find_parent_index(int index) { return (index - 1) / 2; }
    int find_left_index(int index) { return 2 * index + 1; }
    int find_right_index(int index) { return 2 * index + 2; }

    public:
    void build_heap(vector<int>&arr){
      // All Non Leaf Nodes apply heapify
      // TC: O(N)
      heap = arr;
      int n = heap.size();

      for(int i=(n/2-1); i>=0; i--){
        down_heapify(i);
      }
    }

    void up_heapify(int index){
      if(index == 0)return;
      int parent = find_parent_index(index);
      if(heap[index] < heap[parent]){
        swap(heap[parent],heap[index]);
        up_heapify(parent);
      }
    }
    void down_heapify(int index){
      int left_index = find_left_index(index);
      int right_index = find_right_index(index);
      int smallest_index = index;
      if(left_index < heap.size() && heap[left_index] < heap[index]){
        smallest_index = left_index;
      }
      if(right_index < heap.size() && heap[right_index] < heap[smallest_index]){
        smallest_index = right_index;
      }

      if(smallest_index != index){
        swap(heap[index],heap[smallest_index]);
        down_heapify(smallest_index);
      }
    }
    void push(int element)
    {
      heap.push_back(element);
      up_heapify(heap.size()-1);
    }

    void pop()
    {
      if(heap.empty())return;
      heap[0] = heap.back();
      heap.pop_back();
      if(!heap.empty())down_heapify(0);
    }

    int top()
    {
      if(heap.empty()){
        return -1;
      }
      return heap[0];
    }
  };

  class MaxHeap{
    vector<int>heap;
    int get_parent(int index){return (index-1)/2;}
    int get_left_index(int index){return 2*index+1;}
    int get_right_index(int index){return 2*index+2;}

    public:
    void build_heap(vector<int>&arr){
      heap = arr;
      int n = heap.size();

      for(int i=(n/2)-1 ; i>=0; i--){
        // Non Leaf to Root
        heapify(i,n);
      }
    }
    void heapify(int i,int n){
      int left_index = get_left_index(i);
      int right_index = get_right_index(i);
      int greatest_index = i;

      if(left_index < n && heap[left_index] > heap[greatest_index]){
        greatest_index = left_index;
      }
      if(right_index < n && heap[right_index] > heap[greatest_index]){
        greatest_index = right_index;
      }
      
      if(greatest_index != i){
        swap(heap[i], heap[greatest_index]);
        heapify(greatest_index,n);
      }
    }

    void heap_sort(vector<int>&arr){
      heap = arr;
      int n = arr.size();
      build_heap(arr);

      for(int i=n-1; i>0; i--){
        swap(heap[0],heap[i]);
        heapify(0,i);
      }

      arr = heap;

    }
  };
};

int main()
{
  cout << "\n";
  Solution sol = Solution();
  sol.solution();
  cout << "\n";
}