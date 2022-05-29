class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0, n=prices.size();
        
        int minim=prices[0];
        for(int i=1;i<n;i++){
            minim=min(prices[i], minim);
            profit=max(profit, prices[i]-minim);
            
        }
        return profit;
        
    }
};