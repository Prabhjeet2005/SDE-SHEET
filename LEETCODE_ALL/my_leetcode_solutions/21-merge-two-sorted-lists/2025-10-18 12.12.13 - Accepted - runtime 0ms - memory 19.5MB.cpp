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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list3 = new ListNode(-1); // Dummy Node
        ListNode* newList = list3;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val < list2 -> val){
                newList->next = list1;
                newList = newList->next;
                list1 = list1->next;
            }else{
                newList->next = list2;
                newList = newList->next;
                list2 = list2->next;
            }
        }

        if(list1 != nullptr){
            newList -> next = list1;
        }
        if(list2 != nullptr){
            newList->next = list2;
        }

        return list3->next;

    }
};