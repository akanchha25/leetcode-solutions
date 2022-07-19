class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int l=0,h=nums.size()-1;
        
        while(l<=h)
        {
            int mid=l+ ((h-l)/2);
            
           
            if((mid==0 || nums[mid-1]>nums[mid]) &&(mid==nums.size()-1 || nums[mid]<nums[mid+1]))
            {
                
                return nums[mid];
            }
            else if(nums[l]>nums[mid])
            {
                h=mid-1;
            }
            
            else if(nums[mid]>nums[h])
            {
                l=mid+1;
            }
            else {
                return nums[l];
            }
        }
        return -1;
        
    }
};