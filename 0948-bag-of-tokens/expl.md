ASKED IN: **GOOGLE**!     
        
![image](https://user-images.githubusercontent.com/73538974/253866191-1e5cf29e-6bf5-44dc-9b8a-34dc18f20799.png)
        
![WhatsApp Image 2023-07-17 at 12 18 23](https://user-images.githubusercontent.com/73538974/253870263-955fa6ed-cd7b-4ea3-85c4-06681ae9014e.jpg)
![WhatsApp Image 2023-07-17 at 12 18 22](https://user-images.githubusercontent.com/73538974/253870298-f14d9817-f75e-4246-9f13-8ec60d564083.jpg)
![WhatsApp Image 2023-07-17 at 12 18 22](https://user-images.githubusercontent.com/73538974/253870317-1f872bd6-960a-4702-8d91-ee91ea72d689.jpg)
        

```
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
```
​
