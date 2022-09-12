class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.size()==0 || (tokens.size()==1 && tokens[0]>power))
            return 0;
        if(tokens.size()==1 && tokens[0]<power)
            return 1;
        int i=0,j=tokens.size()-1,score=0,max_score=0;
        sort(tokens.begin(),tokens.end());
        while(i<=j){
            while(tokens[i]<=power){
                power-=tokens[i];
                score++;
                max_score = max(max_score,score);
                i++;
            }
            if(score>0){
                score--;
                power+=tokens[j];
                j--;    
            }
            else return max_score;
        }
        return max_score;
    }
};