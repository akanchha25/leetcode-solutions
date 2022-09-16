class Solution {
public:
    
    void solve(vector<int> arr,vector<int>& res,vector<vector<int>> & ans){
        if(arr.size()==0){
            ans.push_back(res);
            return;
        }
        
        vector<int> op1=res;
        vector<int> op2=res;
        op2.push_back(arr[0]);
        arr.erase(arr.begin()+0);
        solve(arr,op1,ans);
        solve(arr,op2,ans);
        return;
    }
    
    
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
         vector<int> res={};
        vector<vector<int>> ans;
        solve(nums,res,ans);
        return ans;
        
        
    }
};