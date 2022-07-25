class Solution {
public:
   bool isAllocation_possible(vector<int>& weights, int days,int max_weight)
    {
        int day=1,current_weight=0;
        for(int i=0;i<weights.size();i++)
        {
            if(current_weight + weights[i]>max_weight)
            {
                day++;
                if(day>days)
                    return false;
                current_weight=weights[i];
            }
            else{
                current_weight+=weights[i];
            }
        }
       return true;
    }
    
    
    
    int shipWithinDays(vector<int>& weights, int days) {
        int res=INT_MIN;
      
        int l=*max_element(weights.begin(), weights.end());   
        int h=accumulate(weights.begin(), weights.end(), 0);
        
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(isAllocation_possible(weights,days,mid))
            {
                res=mid;
                h=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return res;
        
    }
};