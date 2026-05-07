#include<iostream>

using namespace std;

class Database{
  private:
  Database(){}

  public:
  static Database* get_instance(){
    static Database shared_instance;
    return &shared_instance;
  }

  void run_query(string query){
    cout<<"Running Query: "<<query<<"\n";
  }
};

int main(){
  Database* db = Database::get_instance();
  db->run_query("Select * from Users");
}