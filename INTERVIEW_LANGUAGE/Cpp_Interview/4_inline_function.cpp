#include<iostream>
using namespace std;

inline int cube(int number){
  return number*number*number;
}

int main(){
  cout<<"Cube Of 3 is: "<<cube(3)<<"\n";
}