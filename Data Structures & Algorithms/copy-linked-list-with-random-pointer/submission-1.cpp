/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node *, Node *> hash;
        hash[nullptr] = nullptr;
        Node *cur = head;
        while(cur){
            Node *nd = new Node(cur->val);
            hash[cur] = nd;
            cur = cur->next;
        }
        cur = head;
        while(cur){
            hash[cur]->next = hash[cur->next];
            hash[cur]->random = hash[cur->random];
            cur = cur->next;
        }
        return hash[head];
    }
};
