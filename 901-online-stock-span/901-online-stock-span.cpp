class StockSpanner {
public:
    
    stack<pair<int,int>> st;
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        int res=1;
        if(st.size()==0){
            st.push({price,res});
        }
        
            else{
                while(!st.empty() && st.top().first<=price){
                    res+=st.top().second;
                    st.pop();
                }
                
                st.push({price,res});
                
            }
        
        return st.top().second;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */