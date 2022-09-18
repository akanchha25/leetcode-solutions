class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>st;
        int ans=0;
        for(int i=0;i<height.size();i++){
            int prev=0; 
            if(height[i]==0)continue;
            while(!st.empty()){
                ans+=(min(height[i],height[st.top()])-prev)*(i-st.top()-1);
                if(height[st.top()]<=height[i]){
                    prev=max(height[st.top()],prev);
                    if(height[st.top()]==height[i]){
                        st.pop();
                        break;
                    }
                    else st.pop();
                }
                else break;
            }
            st.push(i);
        }
        return ans;
    }
};