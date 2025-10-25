
#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
  int data;
  Node* next;
  Node(int data)
  {
    this->data = data;
    this->next = nullptr;
  }
};

class Solution
{
  Node* createLL(vector<int>&arr){
    if(arr.empty() ){
      return nullptr;
    }
    if(arr.size() == 1){
      return new Node(arr[0]);
    }

    Node* head = new Node(arr[0]);
    Node* curr = head;

    for(int i=1; i<arr.size() ;i++){
      curr->next = new Node(arr[i]);
      curr = curr->next;
    }
    return head;
  }

  void printLL(Node*head){
    if(head==nullptr)return;
    cout<<head->data;
    printLL(head->next);
  }

  int findLength(Node*head){
    if(head == nullptr)return 0;
    if(head->next == nullptr)return 1;

    int remainingLLLength = findLength(head->next);
    return remainingLLLength + 1;
  }

  int sumValues(Node* head){
    if(head == nullptr)return 0;
    if(head->next == nullptr)return head->data;

    int remainingSum = sumValues(head->next);
    return head->data + remainingSum;
  }

  bool findValue(Node* head,int value){
    if(head == nullptr)return false;

    bool foundInRemainingLL = findValue(head->next,value);
    bool foundCurr = false;
    if(head->data == value)foundCurr=true;
    return foundCurr || foundInRemainingLL;

  }

  Node* reverseLL(Node* head){
    if(head == nullptr || head->next == nullptr){
      return head;
    }

    Node* reversedHead = reverseLL(head->next);
    head->next->next = head;
    return reversedHead;

  }
public:
  void solution()
  {
    vector<int> arr = {1, 2, 3, 4};
    Node *head = createLL(arr);
    printLL(head);
    int length = findLength(head);
    cout<<"Length: "<<length<<"\n";
    int sum = sumValues(head);
    cout<<"Sum: "<<sum;
    bool findVal = findValue(head,3);
    cout<<"Found?: "<<findVal;
    head = reverseLL(head);
    printLL(head);
  }
};

int main()
{
  Solution sol = Solution();
  cout << "\n";
  sol.solution();
  cout << "\n";
}
