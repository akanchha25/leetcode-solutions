class Solution {
public:
    vector<int> ans;
   static bool cmp(pair<int,int>&a ,pair<int,int>&b){
        return a.second>b.second;
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        vector<pair<int,int>> v(mp.begin(),mp.end());
        
        sort(v.begin(),v.end(),cmp);
        for (int i=0;i<k;i++){
            ans.push_back(v[i].first);
        }
        
        
      return ans;  
    }
};