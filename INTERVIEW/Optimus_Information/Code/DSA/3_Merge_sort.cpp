#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>&arr,int mid,int start,int end){
  vector<int>temp;

  int i=start,j=mid+1;

  while(i <= mid && j<=end){
    if(arr[i] <= arr[j]){
      temp.push_back(arr[i]);
      i++;
    }
    else{
      temp.push_back(arr[j]);
      j++;
    }
  }
  // Add Left Over Elements
  while(i <= mid){
    temp.push_back(arr[i]);
    i++;
  }
  while(j <= end){
    temp.push_back(arr[j]);
    j++;
  }

  for(int i=start;i<=end;i++){
    arr[i] = temp[i-start];
  }
}

void merge_sort(vector<int>&arr,int start,int end){
  if(start >= end)return; // Base case 0 or 1 elements

  int mid = start + (end - start)/2;
  merge_sort(arr,start,mid);  // Left Half
  merge_sort(arr,mid+1,end);  // Right Half

  merge(arr,mid,start,end);
}

int main(){
  vector<int>arr = {33,2,55,8,1};
  merge_sort(arr,0,arr.size()-1);

  for(auto&element:arr){
    cout<<element<<" ";
  }
}