class MyHashMap {
public:
    std::vector<int> vec = std::vector<int>(1000005,-1);
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        vec[key]=value;
    }
    
    int get(int key) {
        if(vec[key]==-1){
            return -1;
        } else {
            return vec[key];
        }
    }
    
    void remove(int key) {
        vec[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */