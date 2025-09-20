#include <iostream>
#include <vector>
using namespace std;

template <typename T>

class Node
{
public:
  T data;
  Node<T> *next;
  Node(int data)
  {
    this->data = data;
    this->next = nullptr;
  }
  Node(int data, Node *next)
  {
    this->data = data;
    this->next = next;
  }
};

class Solution
{
  Node<int> *convertArrToLL(vector<int> &arr)
  {
    Node<int> *head = new Node<int>(arr[0]);
    Node<int> *temp = head;
    for (int i = 1; i < arr.size(); i++)
    {
      temp->next = new Node<int>(arr[i]);
      temp = temp->next;
    }
    return head;
  }
  void printLL(Node<int> *&head)
  {
    Node<int> *temp = head;
    while (head != nullptr)
    {
      cout << head->data << ", ";
      head = head->next;
    }
  }
  bool findElementLL(Node<int> *&head, int value)
  {
    Node<int> *temp = head;
    while (temp != nullptr)
    {
      if (temp->data == value)
      {
        return true;
      }
      temp = temp->next;
    }
    return false;
  }

  Node<int> *deleteBegLL(Node<int> *&head)
  {
    if (head == nullptr)
    {
      return nullptr;
    }
    if (head->next == nullptr)
    {
      delete head;
      return nullptr;
    }
    Node<int> *temp = head;
    head = head->next;
    delete temp;
    return head;
  }
  Node<int>*deleteEndLL(Node<int>*&head){
    if(head == nullptr){
      return nullptr;
    }
    if(head -> next == nullptr){
      delete head;
      return nullptr;
    }
    Node<int>* temp = head;
    while(temp -> next -> next != nullptr){
      temp = temp->next;
    }
    Node<int>*nextElement = temp->next->next;
    delete temp->next;
    temp->next = nextElement;
    return head;
  }

  Node<int>* deletePositionLL(Node<int>*&head,int position){
    /*
    If head nullptr return nullptr
    if position == 1 delete head & return nullptr
    
    */

   if(head == nullptr){
    return nullptr;
   }
   if(head->next == nullptr && position == 1){
    delete head;
    return nullptr;
   }
   Node<int>*nextElement = head->next;
   Node<int>*currElement = head;
   int count = 0;

   while(nextElement != nullptr){
    count++;
    if(count == position){
      
    }
   }
  }

public:
  void
  solution()
  {
    vector<int> arr = {4, 6, 3, 2, 7};
    Node<int> *head = convertArrToLL(arr);
    bool found = findElementLL(head, 2);
    cout << "Found In LL: " << found << "\n";
    // head = deleteBegLL(head);
    // head = deleteEndLL(head);
    head = deletePositionLL(head,4);
    printLL(head);
  }
};

int main()
{
  cout << "\n";
  Solution sol = Solution();
  sol.solution();
  cout << "\n";
}