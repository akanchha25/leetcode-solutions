class Solution {
public:
    
    bool isValid(string s) {
        stack<char> v;
        
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
        
       return v.empty() ? true : false; 
    }
};