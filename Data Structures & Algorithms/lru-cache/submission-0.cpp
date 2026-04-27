struct Node{
    int key;
    int val;
    Node *next;
    Node *prev;
    Node() : key{-1}, val{-1}, next{nullptr}, prev{nullptr} {}
    Node(int k, int v) : key{k}, val{v}, next{nullptr}, prev{nullptr} {}
};
class LRUCache {
public:
    int cap;
    Node *head;
    Node *cur;
    unordered_map<int, Node *> table;
    LRUCache(int capacity) {
        this->cap = capacity;
        head = new Node();
        cur = head;
    }

    void push(int key, int val){
        Node *nd = new Node(key, val);
        cur->next = nd;
        nd->prev = cur;
        cur = nd;
        table[key] = nd;
    }
    
    void pop(Node *to_remove){
        if(!to_remove) return;
        if(to_remove->next) to_remove->next->prev = to_remove->prev;
        if(to_remove->prev) to_remove->prev->next = to_remove->next;
        if(to_remove == cur) cur = cur->prev;
    }

    int get(int key) {
        if(table.find(key) != table.end()){
            int k = table[key]->key;
            int v = table[key]->val;
            pop(table[key]);
            table.erase(key);
            push(k, v);
            return v;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(table.find(key) != table.end()){
            Node *tmp = table[key];
            pop(table[key]);
            delete tmp;
            table.erase(key);
        }
        push(key, value);
        if(table.size() > cap){
            Node *tmp = head->next;
            table.erase(head->next->key);
            pop(head->next);
            delete tmp;
        }
    }
};
