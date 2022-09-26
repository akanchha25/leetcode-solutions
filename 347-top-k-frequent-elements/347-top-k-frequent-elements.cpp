class Solution {
public: vector<int> ans;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
        
        for(auto x: nums)
            mp[x]++;
        
        vector<int> freq[n+1];    // arrays of vectors
        
        for(int i=0;i<n;i++){
            
            int f=mp[nums[i]];
            
            if(f != -1){
                 freq[f].push_back(nums[i]);
                
                mp[nums[i]]=-1;
            }
        }
        
        int count=0;
        for(int i=nums.size();i>=0;i--){
            
            for(auto x: freq[i]){
                ans.push_back(x);
                count++;
                if(count==k)
                    return ans;
            }
        }
        
       return ans; 
        
    }
};







/* [ using heap ]

    vector<int> ans;
 priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
        unordered_map<int,int> mp;
        
        for(auto x:nums)   
            mp[x]++;
        
        for(auto x: mp){
            pq.push({x.second,x.first});
        }
        
        while(k--){
            ans.push_back(pq.top().second);
                pq.pop();
        }
        
        return ans;
        
        */