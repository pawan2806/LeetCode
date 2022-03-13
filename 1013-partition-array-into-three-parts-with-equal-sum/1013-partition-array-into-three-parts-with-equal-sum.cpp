class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int sum2=0, n=arr.size();
        for(int i=0;i<n;i++){
            sum2+=arr[i];
        }
        if(sum2%3!=0){
            return false;
        }
        int sum=sum2/3;
        int p=0, a=0;
        for(int i=0;i<n;i++){
            p+=arr[i];
                if(p==sum){
                    p=0;
                    a++;
                }
        }
        if(a>=3){
            return true;
        }
        return false;
        
    }
};