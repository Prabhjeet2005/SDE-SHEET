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
        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        int count = 1;

        ListNode* slow = dummyHead;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr && count < n){
            count++;
            fast = fast->next;
        }

        while(fast != nullptr && fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* nodeToRemove = slow->next;
        slow->next = slow->next->next;
        delete nodeToRemove;

        return dummyHead->next;
    }
};