#include<iostream> 
#include<vector>
using namespace std;

int find_partition(vector<int>&arr,int start,int end){
  int i=start;  // Boundary for Lesser Elements
  int pivot_element = arr[start];
  // SWAP on fly without counting
  for(int j=start+1; j<=end; j++){
    if(arr[j] <= pivot_element){
      i++;
      swap(arr[i],arr[j]);
    }
  }
  swap(arr[start],arr[i]);
  return i;
}

void quick_sort(vector<int>&arr,int start,int end){
  if(start >= end)return;
  int partition = find_partition(arr,start,end);
  quick_sort(arr,start,partition-1);
  quick_sort(arr,partition+1,end);
}

int main(){
  vector<int>arr = {22,3,1,55,7};
  quick_sort(arr,0,arr.size()-1);
  for(auto &element:arr){
    cout<<element<<" ";
  }
  cout<<"\n";
}
