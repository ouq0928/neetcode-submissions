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
    void reorderList(ListNode* head) {
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *cur = slow->next;
        ListNode *prev = slow->next = nullptr;
        while(cur){
            ListNode* temp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = temp;
        }
        ListNode *left = head;
        cur = prev;
        while(cur){
            ListNode *temp1 = left->next;
            ListNode *temp2 = cur->next;
            left->next = cur;
            cur->next = temp1;
            left = temp1;
            cur = temp2;
        }
    }
};
