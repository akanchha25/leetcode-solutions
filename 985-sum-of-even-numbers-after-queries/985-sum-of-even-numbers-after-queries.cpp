class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int sum=0;
        for(auto i:nums)
            if(i%2==0)
                sum+=i;
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int tmp=nums[queries[i][1]];
            if((tmp+queries[i][0])%2==0){
                if(tmp%2==0)
                    sum-=tmp;
                 nums[queries[i][1]]+=queries[i][0];
                sum+=nums[queries[i][1]];               
            }
            else{
                    if(tmp%2==0)
                    sum-=tmp;
                  nums[queries[i][1]]+=queries[i][0];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};