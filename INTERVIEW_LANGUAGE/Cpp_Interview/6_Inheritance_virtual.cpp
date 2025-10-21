#include <iostream>
using namespace std;

class Vehicle
{
public:
  virtual void engine() // virtual ignore this
  {
    cout << "Engine From Vehicle";
  }
};

class Car : public Vehicle
{
public:
  void engine() 
  {
    cout << "Engine From Car";
  }
};

int main()
{
  Vehicle* vehicleObj = new Car();
  vehicleObj->engine(); // This Will Call Vehicle's engine
}