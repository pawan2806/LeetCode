class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> temp(26, -1);
        int n=s.length();
        for(int i=0;i<n;i++){
            temp[s[i]-'a']=i;
        }
        vector<int> ans;
        int maxcur=temp[s[0]-'a'], st=0;
        for(int i=0;i<n;i++){ 
            maxcur=max(maxcur,temp[s[i]-'a'] );
            if(maxcur==i){
                ans.push_back(i-st+1);
                
                st=i+1;
                if(st<n)
                maxcur=temp[s[st]-'a'];
            }
        }
        return ans;
        
    }
};