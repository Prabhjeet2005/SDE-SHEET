#include<iostream>
using namespace std;

class Base{
  private:
  int basePrivate;
  protected:
  int baseProtected;
  public:
  Base(){
    basePrivate = 10;
    baseProtected = 10;
  }
};
class Derived:public Base{
  public:
  void displayBase(){
    // cout<<"Base Private: "<<basePrivate;
    cout<<"Base Protected: "<<baseProtected;
  }
};

int main(){
  Derived derivedObj;
  derivedObj.displayBase();
  // derivedObj.baseProtected;
}