/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*>set;
        ListNode* curr = head;
        while(curr!=nullptr){
            if(set.find(curr) != set.end()){
                return 1;
            }
            set.insert(curr);
            curr = curr->next;
        }
        return 0;
    }
};