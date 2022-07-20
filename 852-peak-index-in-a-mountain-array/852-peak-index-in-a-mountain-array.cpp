class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        
        
        int l=0,h=nums.size()-1;
        
        while(l<=h)   
        {
          int mid= l+((h-l)/2);
            
            if((mid==0 ||nums[mid]>nums[mid-1]) &&(mid==nums.size()-1 || nums[mid]>nums[mid+1]))
                
            {
                return mid;
            }
            else if(nums[mid]>nums[mid+1] && nums[mid]<nums[mid-1])
            {
                h=mid-1;
            }
            else {
                l=mid+1;
            }
        }
        return -1;
        
    }
};