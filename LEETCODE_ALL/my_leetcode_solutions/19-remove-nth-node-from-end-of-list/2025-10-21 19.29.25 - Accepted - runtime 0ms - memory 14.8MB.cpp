/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        int count = 1;

        while(fast != nullptr && count <= n){
            fast = fast->next;
            count++;
        }

        while(fast != nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }

        if(fast == nullptr){
            ListNode* newHead = head->next;
            delete head;

            return newHead;;
        }

        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;

        return head;
    }
};