class Solution {
public:
    int kthGrammar(int n, int k) {
       int ans;
        if(n==1){
            return 0;
        }
    
        int mid=pow(2,n-1)/2;
        if(k<=mid){
          ans=  kthGrammar(n-1,k);
        }
        else{
            ans =!( kthGrammar(n-1,(k-mid)));
        }
        
        return ans;
    }
};