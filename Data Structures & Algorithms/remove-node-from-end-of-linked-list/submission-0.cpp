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
    int cntlen(ListNode *head){
        int res = 0;
        ListNode *cur = head;
        while(cur){
            cur = cur->next;
            res++;
        }
        return res;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *cur = head;
        ListNode *prev = dummy;
        int len = cntlen(head);
        if(len == 1) return nullptr;
        int pos = len - n;
        while(pos--){
            prev = cur;
            cur = cur->next;
        }
        prev->next = cur->next;
        delete cur;
        return dummy->next;
    }
};
