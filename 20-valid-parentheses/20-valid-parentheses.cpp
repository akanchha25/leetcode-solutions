class Solution {
public:
    bool check(char a,char b){
        
        return (a=='(' && b==')' ||a=='{' && b=='}'||a=='[' && b==']' );
    }
    
    bool isValid(string str) {
   /*     stack<char> v;
        
        map<char,char> mapping;
        mapping['}']='{';
        mapping[')']='(';
        mapping[']']='[';
        
        map<char,char>::iterator itr;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='{' || s[i]=='(' || s[i]=='[')
            {
                v.push(s[i]);
            }
            else if (s[i]=='}' || s[i]==')' || s[i]==']')
            {
                if(v.empty())
                {
                    return false;
                }
                else
                {
                    char temp=v.top();
                    itr=mapping.find(s[i]);
                    if(temp==itr->second)
                    {
                      v.pop();  
                    }
                    else return false;
                }
            }
        
        }
        
       return v.empty() ? true : false; */
        
        stack<char> st;
        
        
        for(int i=0;i<str.length();i++){
            
            if(str[i]=='(' || str[i]=='{' || str[i]=='['){
                
                st.push(str[i]);
            }
            else{
                if(st.empty()){
                    return false;
                }
                else if(check(st.top(),str[i])){
                    st.pop();
                }
                else return false;
            }
        }
        return st.empty()?true:false;
       
    }
};