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
    ListNode* reverseKNodes(ListNode* head){
        if(!head || !head->next)return head;

        ListNode* prev = nullptr;
        ListNode* curr =  head;
        ListNode* nextNode = head->next;

        while(curr){
            curr->next = prev;
            prev = curr;
            curr = nextNode;
            if(nextNode)nextNode = nextNode->next; 
        }
        return prev;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* curr = dummy;

        while(curr->next){
            ListNode* prev = curr;
            ListNode* kGroupEnd = curr->next;
            int i=0;
            while(i<k && curr){
                curr = curr->next;
                i++;
            }
            if(!curr)break;

            ListNode* kGroupStart = curr;
            prev->next = kGroupStart;
            ListNode* nextGroup = curr->next;
            curr->next = nullptr;
            ListNode* lastNodeGroup = kGroupEnd;
            kGroupEnd = reverseKNodes(kGroupEnd);
            lastNodeGroup->next = nextGroup;
            curr = lastNodeGroup;
        }

        return dummy->next;
    }
};