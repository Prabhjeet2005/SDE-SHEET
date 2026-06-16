#include<iostream>
using namespace std;

class Enemy{
  public:
  // Pure Virtual Function
  virtual void attack() = 0;
};

class Zombie: public Enemy{
  public:
  void attack() override{
    cout<<"Zombie is Attacking\n";
  }
};

class Vampire: public Enemy{
  public:
  void attack() override{
    cout<<"Vampire is attacking\n";
  }
};

class EnemySpawn{
  public:
  static Enemy* spawn_enemy(int type){
    if(type == 1)return new Zombie();
    if(type == 2)return new Vampire();
    return nullptr;
  }
};

int main(){
  Enemy* e = EnemySpawn::spawn_enemy(2);
  e->attack();
}