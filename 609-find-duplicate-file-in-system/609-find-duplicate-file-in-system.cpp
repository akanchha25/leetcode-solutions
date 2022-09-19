class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ans ;
        
        unordered_map<string, vector<string>> mp ;
        for(int i = 0 ; i < paths.size() ; i++) {
            string directory = "" ;
            int nsp = 0 ;
            
            while(nsp < paths[i].size() && paths[i][nsp] != ' ')
                nsp++ ;
            
            directory = paths[i].substr(0, nsp) ;
            int start = nsp + 1 , contentInd ;
            string currDir ;
            for(int j = start ; j < paths[i].size() ; j++) {
                if(paths[i][j] == '(') {
                    currDir = directory + "/" + paths[i].substr(start, j - start) ;
                    
                    contentInd = ++j ;
                    while(j < paths[i].size() && paths[i][j] != ')')
                        j++ ;
                    
                    mp[paths[i].substr(contentInd, j - contentInd)].push_back(currDir) ;
                }
                
                if(paths[i][j] == ' ') {
                    start = j + 1 ;
                }
            }
        }
        
        for(auto &[content, dir] : mp) {
            if(dir.size() >= 2)
                ans.push_back(dir) ;
        }
        
        return ans ;
    }
};