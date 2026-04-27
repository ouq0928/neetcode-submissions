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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right) return head;
        ListNode *dummy = new ListNode(0, head);
        ListNode *prev = dummy;
        ListNode *cur = head;
        ListNode *nxt = cur->next;
        ListNode *nnxt = nxt->next;
        ListNode *first = cur;
        int cnt1 = 1;
        int cnt2 = 1;
        while(cnt2 < right){
            while(cnt1 < left){
                prev = cur;
                cur = nxt;
                first = cur;
                nxt = cur->next;
                nnxt = nxt->next;
                cnt1++;
                cnt2++;
                // cout << "#\n";
            }
            nxt->next = cur;
            cur = nxt;
            nxt = nnxt;
            if(nxt) nnxt = nxt->next;
            cnt2++;
        }
        prev->next = cur;
        if(nxt == nullptr){
            first->next = nullptr;
        }else first->next = nxt;
        return dummy->next;
    }
};