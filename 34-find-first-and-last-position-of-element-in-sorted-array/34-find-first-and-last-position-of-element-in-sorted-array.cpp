class Solution {
public:
    
    
      
       int find_helper(vector<int>& nums, int target,bool isFirst) 
           
       {
            int l=0,h=(nums.size()-1);
        int ans=-1;
        while(l<=h)
        {
            int mid=l+((h-l)/2);
            if(target<nums[mid])
            {
                h=mid-1;
            }
            else if(target>nums[mid])
            {
                l=mid+1;
            }
            else 
            { 
                ans=mid;
                if(isFirst)
                h=mid-1;
                else 
                    l=mid+1;
            }
        }
        return ans;
        
       }
    
    
    vector<int> searchRange(vector<int>& nums, int target) {
        
       int left=find_helper( nums, target,1) ;
        int right=find_helper( nums, target,0);
        if(left<=right)
            return{left,right};
        else
            return{-1,-1};
      
        

        
        
            
        
        
        
    }
};


//code using find helper function