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
    class customComparator {
    public:
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // 3,5
        }
    };

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, customComparator> minHeap;

        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != nullptr) {
                minHeap.push(lists[i]);
            }
        }

        ListNode* ans = new ListNode(-1); // Dummy Head
        ListNode* curr = ans;

        while (!minHeap.empty()) {
            ListNode* minNode = minHeap.top();
            minHeap.pop();
            ListNode* minNodeNext = minNode->next;
            curr->next = minNode;
            curr = curr->next;
            if(minNodeNext != nullptr)minHeap.push(minNodeNext);
        }

        return ans->next;
    }
};