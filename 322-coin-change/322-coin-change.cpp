class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
//        
        int n=coins.size();
        sort(coins.begin(), coins.end());
        vector<int> dp(amount+1, amount+1);
        dp[0]=0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<n;j++){
                if(coins[j]<=i){
                     dp[i]=min(dp[i], dp[i-coins[j]]+1);
                } else {
                    break;
                }
               
            }
        }
         return dp[amount] > amount ? -1 : dp[amount];
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        // int dp[++n];
        // dp[0] = 0;
        // // more convenient to have the coins sorted
        // sort(begin(coins), end(coins));
        // // populating our dp array
        // for (int i = 1; i < n; i++) {
        //     // setting dp[0] base value to 1, 0 for all the rest
        //     dp[i] = INT_MAX;
        //     for (int c: coins) {
        //         if (i - c < 0) break;
        //         // if it was a previously not reached cell, we do not add use it
        //         if (dp[i - c] != INT_MAX) dp[i] = min(dp[i], 1 + dp[i - c]);
        //     }
        // }
        // return dp[--n] == INT_MAX ? -1 : dp[n];
            
        
     
    }
};