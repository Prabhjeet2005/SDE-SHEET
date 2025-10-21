#include<iostream>
#include<stdexcept>
using namespace std;

int main(){

  try{
    int a = 10,b=0;
    if(b==0){
      throw runtime_error("Divide By 0");
    }
    cout<<"No Error Thrown";
  }catch(const exception &e){
    cerr<<"Error Caught: "<<e.what()<<"\n";
  }

  catch(...){
    cerr<<"Unknown Error Caught"<<"\n";
  }
}