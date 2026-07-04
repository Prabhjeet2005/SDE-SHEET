#include<iostream>
using namespace std;

struct ListNode{
  int data;
  ListNode* next;
  ListNode(int data){
    this->data = data;
    next = nullptr;
  }
};

class Solution{
  public:
  void solution(){
    ListNode* head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);

    reverse_LL(head);

    print_LL(head);
  }
  private:
  void reverse_LL(ListNode* &head){
    if (!head || !head->next)return;

    ListNode* prev = nullptr;
    ListNode* curr = head;
    ListNode* next_node = head->next;

    while(curr){
      curr->next = prev;
      prev = curr;
      curr = next_node;
      if(next_node){next_node = next_node->next;}
    }
    head = prev;
  }

  void print_LL(ListNode* head){
    if(!head)return;

    ListNode* curr = head;
    while(curr){
      cout<<curr->data<<" ";
      curr = curr->next;
    }
  }
};

int main(){
  Solution sol = Solution();
  sol.solution();
}