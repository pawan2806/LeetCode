class MyHashSet {
public:
    unordered_map<int,int> m;
    MyHashSet() {
        m.clear();
    }
    
    void add(int key) {
        m[key]++;
    }
    
    void remove(int key) {
        if(m.count(key)){
            m.erase(m.find(key));
        }
    }
    
    bool contains(int key) {
        return m.count(key)>0;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */