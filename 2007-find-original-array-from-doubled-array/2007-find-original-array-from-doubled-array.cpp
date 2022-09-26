class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
//         int n=changed.size();
//         sort(changed.begin(), changed.end());
//         vector<int> ans;
//         map<int,int> s;
//         if(n%2==1){
//             return {};
//         } 
//         for(int i=0;i<n;i++){
           
//                 s[changed[i]]++;
//         }
//         for(int i=0;i<n;i++){
//             if(ans.size()==n/2){
//                 return ans;
//             }
//             if(s[changed[i]]==0){
//                 continue;
//             } else {
//                 cout<<changed[i]<<endl;
//                 s[changed[i]*2]--;
//                 ans.push_back(changed[i]);
//             }
//         }
//         if(ans.size()==n/2){
//             return ans;
//         } else {
//             return {};
//         }
        vector<int> ans;
        if(changed.size()&1) return ans;
        sort(changed.begin(),changed.end());
        unordered_map<int,int> mp;
        for(auto i:changed) mp[i]++;
        
        for(auto i:changed){
            if(mp[2*i] and mp[i])
            {
                mp[i]--;
                mp[2*i]--;
                ans.push_back(i);
            }
        }
        for(auto i=mp.begin();i!=mp.end();i++)
            if(i->second) return {};
        return ans;
    }
};