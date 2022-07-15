class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int l=0,h=(nums.size()-1);
        int first=-1,last=-1;
        
        //for first
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
                first=mid;
                h=mid-1;
            }
        }
        
        //last
          l=0;h=(nums.size()-1);
        
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
                last=mid;
                l=mid+1;
            }
        }
        
        return {first,last};
        
        
            
        
        
        
    }
};