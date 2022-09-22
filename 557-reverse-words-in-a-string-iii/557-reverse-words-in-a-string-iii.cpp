class Solution {
public:
    string reverseWords(string s) {
        stack<char> st;
        string ans = "";
        for(auto it : s)
        {
           if(it == ' ')
           {
               while(!st.empty())
               {
                   ans += st.top();
                   st.pop();
               }
               ans +=" ";
           }else{
               st.push(it);
           }
        }
        
        while(!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};