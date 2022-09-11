bool compare (pair<int,int>&a, pair<int,int>&b){
    if(a.first == b.first)
        return a.second < b.second;
    return a.first > b.first;
}



class Solution {
public:
    int MOD = 1000000007;
    
    int maxPerformance(int n, vector<int>& s, vector<int>& e, int k) {
        vector<pair<int,int>> p;
        for(int i = 0 ; i < n ; i++)
            p.push_back({e[i], s[i]});
        
        // sort by decreasing order of eff
        sort(p.begin(), p.end(), compare);
        
        int eff = INT_MAX;
        long cum_sp = 0;
        long max_perf = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        // go through first k highest eff        
        for(int i = 0 ; i < k ; i++){
            eff = p[i].first;
            cum_sp = (cum_sp + p[i].second);
            pq.push(p[i].second);
            max_perf = max(max_perf, (eff*cum_sp));
        }
        
        // for the remaining eff, consider
        // them only if they have a larger speed
        for(int i = k ; i < n ; i++){
            if(pq.top() < p[i].second){
                eff = p[i].first;
                cum_sp = (cum_sp - pq.top() + p[i].second);
                pq.pop();
                pq.push(p[i].second);
                max_perf = max(max_perf, (eff*cum_sp));
            }
        }       
        return max_perf%MOD;
    }
};