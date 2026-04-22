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
    bool hasCycle(ListNode* head) {
        ListNode *cur1 = head;
        ListNode *cur2 = head;
        while(cur1 && cur2->next){
            cur1 = cur1->next;
            cur2 = cur2->next->next;
            if(!cur2) return false;
            if(cur1 == cur2) return true;
        }
        return false;
    }
};
