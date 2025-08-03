#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <list>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
  // ------------------------------VECTOR------------------------------
  cout << "VECTOR:-\n";
  vector<int> vec = {1, 2, 3, 3, 3, 3, 3};
  vec.push_back(4);                // INSERT
  vec.insert(vec.begin() + 2, 10); // Insert At Index

  auto iterator_vec = find(vec.begin(), vec.end(), 10); // Find
  if (iterator_vec != vec.end())
  {
    cout << "Found: " << *iterator_vec << endl; // If not at end Iterator
  }
  if (!vec.empty())
  {
    vec[0] = 102; // UPDATE
  }
  // REMOVE
  vec.erase(vec.begin() + 1);                              // Erase By Position
  vec.erase(remove(vec.begin(), vec.end(), 3), vec.end()); // Erase By Value

  for (auto i : vec)
  {
    cout << i << " ";
  }
  cout << endl;

  // ------------------------------SET------------------------------
  cout << "\nSET:-\n";
  set<int> set = {1, 2, 4};
  set.insert(3);
  cout << "Found Or Not : " << set.count(3) << endl; // SET FIND (ONLY SET)

  auto it_set = set.find(2);
  if (it_set != set.end())
  {
    cout << "Found In Set: " << *it_set << endl;
  }

  auto iterator_set = find(set.begin(), set.end(), 4); // GENERIC FIND
  if (iterator_set != set.end())
  {
    cout << "Element Found: " << *iterator_set << endl; // ELEMENT FOUND

    set.erase(*iterator_set); // UPDATION (SET IMMUTABLE Re-Assign Key)
    set.insert(40);           // UPDATION
    cout << "Element Found After Updation: " << *iterator_set << endl;
  }
  set.erase(2);
  for (auto it : set)
  {
    cout << it << " ";
  }
  cout << endl;

  // ------------------------------ MAP ------------------------------

  cout << "\nMAP:-\n";
  map<string, int> map;
  map.insert({"Apple", 2});   // INSERT
  map.insert({"Chicken", 5}); // INSERT

  cout << "Apple Count: " << map["Apple"] << endl;

  auto it_map = map.find("Chicken");
  if (it_map != map.end())
  {
    cout << "Found Chicken: " << it_map->second << endl;
  }

  map.erase("Apple");

  for (auto it : map)
  {
    cout << it.first << " : " << it.second << " , ";
  }
  cout << endl;

  // ------------------------------ PRIORITY QUEUE ------------------------------
  cout << "\nPRIORITY QUEUE:-\n";
  priority_queue<int> pq; // MAX HEAP
  pq.push(1);
  pq.push(10);
  pq.push(5);

  cout << "Top MaxHeap: " << pq.top() << endl; // Access Top Element
  pq.pop();
  cout << "After Erasing New Topmost: " << pq.top() << endl;
  cout << endl;
  // ------------------------------ LIST ------------------------------
  cout << "\nLIST-\n";
  list<int> lst = {1, 2, 3, 4, 5};
  lst.push_back(6);
  lst.push_front(0);

  auto it_lst = find(lst.begin(),lst.end(),4);  // FIND
  if(it_lst != lst.end()){
    cout<<"Found In List: "<<*it_lst<<endl; 
  }

  it_lst = find(lst.begin(),lst.end(),3);
  if(it_lst != lst.end()){
    *it_lst=100;  // UPDATION
  }

  lst.remove(1); // REMOVE All 1
  lst.erase(find(lst.begin(),lst.end(),6));

  for (auto &it : lst)
  {
    cout << it << " ";
  }
  cout << endl;
  // ------------------------------  ------------------------------
}