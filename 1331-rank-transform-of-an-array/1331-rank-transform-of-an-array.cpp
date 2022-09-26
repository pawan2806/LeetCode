class Solution {
public:
   vector<int> arrayRankTransform(vector<int>& arr) 
    {
        //map
        int rank=1;               //to assign the rank to the elements
        map<int,vector<int>>mp;   //why map->to ensure the sorted nature of the elements
        
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]].push_back(i);
        }
        vector<int>v;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            v=it->second;   //this vector<int> will have basically all the index of the it->first
            int idx;
            for(int i=0;i<v.size();i++)
            {
                idx=v[i];
                arr[idx]=rank;
            }
            rank++;
        }
        return arr;
        
    }
};