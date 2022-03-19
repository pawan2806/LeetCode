class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        return a[1]<b[1];
    }
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int n=trips.size();
        vector<int> inc(1001,0);
        for(int i=0;i<n;i++){
            inc[trips[i][1]]+=trips[i][0];
            inc[trips[i][2]]-=trips[i][0];
        }
        int currcap=0;
        for(int i=0;i<1001;i++){
            currcap+=inc[i];
            if(currcap>capacity){
                return false;
            }
        }
//         sort(trips.begin(), trips.end(), comp);
//         int n=trips.size();
//         vector<pair<int,int>> drop;
//         for(int i=0;i<n;i++){
//             drop.push_back({trips[i][2], trips[i][0]});
//         }
//         sort(drop.begin(), drop.end());
//         int j=0;
//         int currcap=0;
//         for(int i=0;i<n;i++){
//             int from=trips[i][1];
            
//             while(j<n && drop[j].first<=from){
//                 currcap-=drop[j].second;
//                 j++;
//             }
//             currcap+=trips[i][0];
//             cout<<trips[i][0]<<trips[i][1]<<trips[i][2]<<endl;
//             if(currcap>capacity){
//                 return false;
//             }
//         }
        return true;
    }
};