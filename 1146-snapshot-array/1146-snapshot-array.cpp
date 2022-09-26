class SnapshotArray {
    unordered_map<int,unordered_map<int,int>> hmap;
    vector<int> latestsnap;
    int snapid=0;
public:
    SnapshotArray(int length) {
        vector<int> temp(length+1,0);
        latestsnap=temp;
    }
    
    void set(int index, int val) {
        hmap[snapid][index]=val;
        
        
    }
    
    int snap() {
        snapid++;
        return snapid-1;
    }
    
    int get(int index, int snap_id) {
        
        for(int i=snap_id;i>=0;i--)
        {
            if(hmap[i].count(index)==1)
                return hmap[i][index];
        }
        return 0;
    }
};
/**
 *Your SnapshotArray object will be instantiated and called as such:
 *SnapshotArray* obj = new SnapshotArray(length);
 *obj->set(index,val);
 *int param_2 = obj->snap();
 *int param_3 = obj->get(index,snap_id);
 */