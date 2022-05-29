class Solution {
public:
    int maxProduct(vector<int>& A) {
        
        int maxneg=A[0];
        int maxpos=A[0];
        int ans=A[0];
        int n=A.size();
        if(n==1){
            return A[0];
        }
        for(int i=1;i<n;i++){
            int temp = maxpos;
            maxpos=max(maxpos*A[i], max(maxneg*A[i], A[i]));
            maxneg=min(maxneg*A[i], min(temp*A[i], A[i]));
            ans=max(maxpos, ans);
        }
        return ans;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
//          int N = A.size();
//     if(N == 0) return 0;
//     else if(N == 1) return A[0];
//     else {
//         int max_ending_here = A[0], min_ending_here = A[0];
//         int max_overall = A[0];
        
//         for(int i = 1; i<N; i++){
//             int temp = max_ending_here;
//             max_ending_here = max({A[i], max_ending_here*A[i], min_ending_here*A[i]});
//             min_ending_here = min({A[i], temp*A[i], min_ending_here*A[i]});
//             max_overall = max(max_overall, max_ending_here);
//         }
//         return max_overall;
//     }
    }
};