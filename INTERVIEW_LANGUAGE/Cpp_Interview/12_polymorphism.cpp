#include <iostream>
#include<string>
using namespace std;

class Base
{
public:
  int a = 10,b=20;
  virtual void display()
  {
    cout << "Base Class Display" << "\n";
  }
  void add(int first,int second){
    cout<<"Add Integers: "<<first+second<<"\n";
  }
  void add(string first,string second){
    cout<<"Add Strings: "<<first+second<<"\n";
  }

  Base operator+(Base obj1){
    Base answer;
    answer.a = this->a + obj1.a;
    answer.b = this->b + obj1.b;
    return answer;
  }
};
class Derived : public Base
{
public:
  virtual void display()
  {
    cout << "Derived Class Display" << "\n";
  }
};

int main()
{
  // Derived *b = new Base(); ISA Relationship
  Base *b1 = new Derived();
  b1->display();

  Base *b2 = new Base();
  Base *b3 = new Base();
  Base b4 = *b3 + *b2;
  cout<<"b4.a : "<<b4.a<<"\nb4.b : "<<b4.b<<"\n";
  delete b1;
  delete b2;
  delete b3;

}