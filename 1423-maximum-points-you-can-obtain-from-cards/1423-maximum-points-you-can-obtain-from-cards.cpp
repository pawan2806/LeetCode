class Solution
{
    public:

        int maxScore(vector<int> &C, int K)
        {
            int ans = 0;
            int n = C.size();
            for(int i=0;i<K;i++){
                ans+=C[i];
            }
            int ansmax=ans;
            K--;
            n--;
            while(K>=0){
                ans-=C[K];
                ans+=C[n];
                ansmax=max(ans, ansmax);
                n--;
                K--;
                
            }
            return ansmax;
        }
};