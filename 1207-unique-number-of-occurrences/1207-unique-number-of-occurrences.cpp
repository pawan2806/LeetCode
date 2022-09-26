class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[arr[i]]++;
        }
        unordered_map<int,int>::iterator itr;
        unordered_map<int,vector<int>> m2;
        for(itr=m.begin();itr!=m.end();itr++){
            m2[itr->second].push_back(itr->first);
        }
        unordered_map<int,vector<int>>::iterator itr2;
        for(itr2=m2.begin();itr2!=m2.end();itr2++){
           if(itr2->second.size()>1){
               return false;
           }
        }
        return true;
    }
};