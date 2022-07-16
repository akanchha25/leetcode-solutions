class Solution {
public:
    int mySqrt(int x) {
        
        if(x==0 || x==1)
        {
            return x;
        }
        
        long long int l=1,h=x/2,ans;
        
        while(l<=h)
        {
            long long int mid=l+((h-l)/2);
            long long sqr=mid*mid;
            
            if(sqr>x)
            {
                h=mid-1;
            }
            else if(sqr<x)
            {
                ans=mid;
                l=mid+1;
            }
            else
            {
                return mid;
            }
        }
        return ans;
    }
};