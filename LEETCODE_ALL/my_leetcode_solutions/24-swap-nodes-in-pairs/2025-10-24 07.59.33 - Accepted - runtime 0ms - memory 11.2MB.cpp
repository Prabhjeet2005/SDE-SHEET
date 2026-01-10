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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next){
            return head;
        }

        ListNode* dummyHead = new ListNode(-1);
        dummyHead->next = head;
        ListNode* curr = dummyHead;

        while(curr){
            if(!curr->next || !curr->next->next){
                break;
            }
            ListNode* firstNode = curr->next;
            ListNode* secondNode = curr->next->next;
            ListNode* remainingLL = curr->next->next->next;

            secondNode->next = firstNode;
            firstNode->next = remainingLL;
            curr->next = secondNode;
            curr = firstNode;
        }

        ListNode* finalHead  = dummyHead->next;
        delete dummyHead;
        return finalHead;
    }
};