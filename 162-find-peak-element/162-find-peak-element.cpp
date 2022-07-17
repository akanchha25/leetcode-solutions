class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        
        
        if(nums.size()==1)
        {
            return 0;
        }
          if(nums.size()==2)
        {
              if(nums[0]>nums[1])
              { return 0;}
              else return 1;
        }
        int mid;
        int l=0,h=nums.size()-1;
        
        while(l<=h)
        {
            mid=l+((h-l)/2);
            if((mid==0 || nums[mid]>nums[mid-1]) && (mid==nums.size()-1 || nums[mid]>nums[mid+1]))
            {
                return mid;
            }
            else if(mid>0 && nums[mid-1]>nums[mid])
            {
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }

        
        
 return mid;
        
    }
};