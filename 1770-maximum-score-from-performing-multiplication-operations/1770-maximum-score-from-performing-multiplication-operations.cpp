class Solution {
public:
    int dp[1101][1101];
    int n,m;
    int findMaximum(int i,int j,vector<int> &nums,vector<int> &multipliers)
    {
      
        if(j+i>=m)
            return 0;
        if(dp[i][j]!=INT_MIN)
            return dp[i][j];
        int t1=multipliers[i+j]*nums[i]+findMaximum(i+1,j,nums,multipliers);
        int t2=multipliers[i+j]*nums[n-j-1]+findMaximum(i,j+1,nums,multipliers);
        dp[i][j]=max(t1,t2);
        
        return dp[i][j];
        
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        
        for(int i=0;i<=1100;i++)
            for(int j=0;j<=1100;j++)
                dp[i][j]=INT_MIN;
        
        n=nums.size(),m=multipliers.size();
        return findMaximum(0,0,nums,multipliers);
    }
};