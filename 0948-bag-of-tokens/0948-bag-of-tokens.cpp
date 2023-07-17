class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        
        // using observations
        int n = tokens.size();
        
        sort(tokens.begin(), tokens.end());
        
        int i = 0, j = n - 1;
        
        int score = 0, maxScore = 0;
        
        while(i <= j){
            // can either buy or sell
            // keep increasing until you can find the desired one
            if(power >= tokens[i]){
                // can buy
                power -= tokens[i];
                score++;
                maxScore = max(maxScore, score);        
                i++;
            }else{
                // cannot buy, but can sell the max one
                if(score > 0){
                    power += tokens[j];
                    score--;
                    j--;
                }
                
                else{
                    // no score  and also cannot buy
                    break;
                }
            }
            
            
        }
        
        return maxScore;
        
        
    }
};