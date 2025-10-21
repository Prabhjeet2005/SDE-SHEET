#include<iostream>
using namespace std;

class Base{
  private:
  int a;
  public:
  Base(int a=10){
    this->a = a;
  }
  Base(Base &obj){
    this->a= obj.a;
  }
  void display(){
    cout<<"A: "<<this->a<<"\n";
  }
};

int main(){
  Base obj1;
  Base obj2;
  Base obj3 = obj2;
  obj3.display();
}