#include <iostream>
#include <vector>
using namespace std;
template <typename T>
class Node
{
public:
  T data;
  Node<T> *next;
  Node<T> *prev;
  Node(T data)
  {
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
  }
};

class Solution
{
  Node<int> *covertArrToDLL(vector<int> &arr)
  {
    if(arr.size()==0){
      return nullptr;
    }
    Node<int>*head = new Node<int>(arr[0]);
    if(arr.size()==1){
      return head;
    }
    Node<int>*prevNode = head;

    for(int i=1; i<arr.size();i++){
      Node<int>*newNode = new Node<int>(arr[i]);
      newNode->prev = prevNode;
      prevNode->next = newNode;
      prevNode = newNode;
    }
    return head;
  }

  void printDLL(Node<int>*&head){
    if(head == nullptr){
      return;
    }
    Node<int>*temp = head;
    while(temp != nullptr){
      cout<<temp->data<<", ";
      temp = temp->next;
    }
    cout<<"\n";
  }

public:
  void solution()
  {
    vector<int> arr = {2, 6, 3, 99};
    Node<int> *head = covertArrToDLL(arr);
    printDLL(head);
  }
};

int main()
{
  cout << "\n";
  Solution sol = Solution();
  sol.solution();
  cout << "\n";
}