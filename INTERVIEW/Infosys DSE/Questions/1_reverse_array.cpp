#include<iostream>
#include<vector>
using namespace std;

void reverse_arr(vector<int>&arr){
  int i=0,j=arr.size()-1;

  while(i<j){
    swap(arr[i],arr[j]); // FIX: Move Pointers
    i++;j--;
  }
}

int main(){
  vector<int>arr={1,2,3};

  reverse_arr(arr);

  for(auto &element:arr){
    cout<<element<<", ";
  }
}