#include <iostream>
using namespace std;

class Vehicle
{
public:
  void engine()
  {
    cout << "Engine Present\n";
  }
};

class Car : virtual public Vehicle
{
};

class Truck :virtual public  Vehicle
{
};

// Inherit Vehicle Twice
class PickUpTruck : public Car, public Truck
{
};

int main()
{
  PickUpTruck pick_up_truck_obj = PickUpTruck();
  pick_up_truck_obj.engine();
}
