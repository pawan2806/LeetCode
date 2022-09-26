class DetectSquares {
public:
     map<pair<int, int>,int> mp;
    
    DetectSquares() {
        return ;
    }
    
    void add(vector<int> point) {
        mp[{point[0],point[1]}]++;
        return ;
    }
    
    int count(vector<int> point) {
        int count = 0;
        int x1= point[0], y1 = point[1];
        for(auto pt : mp){
            pair<int,int> it = pt.first;
            if(it.first!=x1 && it.second!=y1 && (abs(it.first-x1)==abs(it.second-y1))){
                count += mp[{it.first,it.second}]*mp[{it.first,y1}]*mp[{x1,it.second}];
            }
        }
        return count;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */