class Solution {
public:
    string intToBinary(int num)
    {
        string str="";
        while(num>0)
        {
            str.push_back(num%2+'0');
            num/=2;
        }
        while(str.size()!=8)
            str.push_back('0');
        reverse(str.begin(),str.end());
        return str;
    }
    bool validUtf8(vector<int>& data) {
        int cnt=0,prevBit=0;
        for(int i=0;i<data.size();i++)
        {
            string str=intToBinary(data[i]);
            if(cnt==0)
            {
                if(str[0]=='0')
                    prevBit=1;
                else if(str[0]=='1'&str[1]=='1'&&str[2]=='0')
                    prevBit=2;
                else if(str[0]=='1'&str[1]=='1'&&str[2]=='1'&&str[3]=='0')
                    prevBit=3;
                else if(str[0]=='1'&str[1]=='1'&&str[2]=='1'&&str[3]=='1'&&str[4]=='0')
                    prevBit=4;
                else
                    return false;
                cnt=prevBit-1;
            }
            else 
            {
                if(str[0]!='1'||str[1]!='0')
                    return false;
                cnt--;
            }
        }
        
        return cnt==0;
        
    }
};