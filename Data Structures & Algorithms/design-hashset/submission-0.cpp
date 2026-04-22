class MyHashSet {
public:
    set<int> mset;
    MyHashSet() {
        
    }
    
    void add(int key) {
        mset.insert(key);
    }
    
    void remove(int key) {
        mset.erase(key);
    }
    
    bool contains(int key) {
        if(mset.count(key)) return true;
        else return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */