class RandomizedCollection {
public:
     map <int, set<int>> m;                          //used to map element with the indices where it is present in vector v
    vector <int> v;                                 //used to store all the elements (contains duplicate as well)
    RandomizedCollection() {}                       //constructor (no such initialisation needed)
    
    bool insert(int val) {
        v.push_back(val);                           //inserting element into vector
        m[val].insert(v.size()-1);                  //insering the index of newly inserted element into map 
        return m[val].size() == 1;                  
    }
    
    bool remove(int val) {
        auto it = m.find(val);                      //used to find if element is present in map
        if(it != m.end()){                          //if it is present,
            auto pos = *it->second.begin();         //pos is an integer and not pointer
            it->second.erase(it->second.begin());   //erases integer from the set stored in map corresponding to the element val
            v[pos] = v.back();                      //element from the back is brought at the index pos
            m[v.back()].insert(pos);                //new index of that element is stored in map
            m[v.back()].erase(v.size()-1);          //erasing the old index from the map
            v.pop_back();                           //erasing the element from vector 
            if (it->second.size() == 0)             //if no indices are present in map corresponding to val in map, it means it was present only once 
                m.erase(it);                        //so erase from map itself
            return true;
        }
        return false;
    }
    
    int getRandom() {
        return v[rand() % v.size()];                //rand() is used to get a random number and it is % by v.size() so that the result is within the size of vector v
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */