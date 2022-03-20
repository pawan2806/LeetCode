class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        int n=tops.size();
       
        int ans=INT_MAX;
        for(int i=1;i<=6;i++){
            int temp=0;
            for(int k=0;k<n;k++){
                if(tops[k]==i || bottoms[k]==i){
                    temp++;
                }
            }
            if(temp<n){
                continue;
            }
            int counter=0;
            for(int j=0;j<n;j++){
                if(tops[j]!=i){
                    counter++;
                }
            }
            int counterdown=0;
            for(int j=0;j<n;j++){
                if(bottoms[j]!=i){
                    counterdown++;
                }
            }
            counter=min(counter, counterdown);
            ans=min(ans, counter);
            
        }
        
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};