class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n==0){
            return 0;
        }
        if (k >= n/2){
            int profit = 0;
            for(int i=1; i<n; i++){
                if (prices[i-1]<prices[i]){
                    profit += (prices[i]-prices[i-1]);
                }
            }
            return profit;
        }
        vector<vector<int>> dp(k+1, vector<int>(n, 0));
        for(int i=1; i<=k; i++){
            int maxTillNow = -prices[0];
            for (int j=1; j<n; j++){
                dp[i][j] = max(dp[i][j-1], prices[j]+maxTillNow);
                
                // net value after buying current stock
                // if net value is greater than prev value then 
                // this stock can give benefit in future
                maxTillNow = max(maxTillNow, dp[i-1][j-1] -prices[j]);
            }
        }
        return dp[k][n-1];
    }
};