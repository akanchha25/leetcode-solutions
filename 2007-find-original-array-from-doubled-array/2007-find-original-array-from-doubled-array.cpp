class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        
        int n=changed.size();
        if(n%2==1)
            return {};
        map<int,int >s;
        for(int i=0;i<n;i++)
            s[changed[i]]++;
        vector<int>v;
        if(s.find(0)!=s.end())
            {
                if(s[0]%2==1)return {};
                while(s[0])
                {
                    v.push_back(0);
                    s[0]-=2;
                }
            }
        for(auto i:s)
        {
            if(i.second==0 || i.first==0)
                continue;  
            else if(s.find(i.first*2)!=s.end())
            {
                   while(i.second && s[i.first*2]>0)
                   {
                       v.push_back(i.first);
                       i.second--;
                       s[i.first*2]--;
                   }
            }
            else
                return{};  
        }
        if(v.size()==n/2)
        return v;
        return {};
    }
};