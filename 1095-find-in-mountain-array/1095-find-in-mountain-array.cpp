/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    
   
    
   
    int left_of_Bitonic_point(int target,MountainArray &num,int peak)
    {
        
        int s=0,e=peak;
        
        while(s<=e)
        {
            int m=s+((e-s)/2);
            
            if(num.get(m)==target)
            {
                return m;
            }
            else if(target>num.get(m))
            {
                s=m+1;
            }
            else {
                e=m-1;
            }
        }
        return -1;
    }
    
     int right_of_Bitonic_point(int target,MountainArray &num,int peak)
    {
        
        int s=peak+1,e=num.length()-1;
        
        while(s<=e)
        {
            int m=s+((e-s)/2);
            
            if(num.get(m)==target)
            {
                return m;
            }
            else if(target<num.get(m))
            {
                s=m+1;
            }
            else {
                e=m-1;
            }
        }
        return -1;
    }
    
    
    
    
    
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int low=0;
        int high=mountainArr.length()-1;
        
        while(low<high)
        {
            int mid=low+((high-low)/2);
            
            if(mountainArr.get(mid)<mountainArr.get(mid+1))
            {
                low=mid+1;
            }
            else high=mid-1;
        }
        int peak=low;
        
        int i1= right_of_Bitonic_point(target,mountainArr,peak);
        int i2=left_of_Bitonic_point( target,mountainArr,peak)  ;  
        
        if(i1==i2)
        {
            return -1;
        }
        else if(i1==-1 && i2!=-1)
        {
            return i2;
        }
        else if(i2==-1 && i1!=-1)
        {
            return i1;
        }
        else {
            return min(i1,i2);
        }
        
    }
};