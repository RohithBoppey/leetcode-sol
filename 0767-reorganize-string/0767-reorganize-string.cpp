class Solution {
public:
    typedef pair<int, char> P;
    
    string reorganizeString(string s) {
        // USING PRIORITY QUEUE SOLUTION
        int n = s.size();
        
        // populating freq array
        vector<int> freq(26, 0);
        for(auto &ch: s){
            freq[ch - 'a']++;
            if(freq[ch - 'a'] > (n + 1) / 2){
                // not possible
                return "";
            }
        }
        
        // pushing the valid ones into priority queue
        priority_queue<P, vector<P>> pq;
        
        for(int i = 0; i < 26; i++){
            if(freq[i] != 0){
                // that means it exists
                pq.push({freq[i], (char)('a' + i)});
            }
        }
        
        // processing the pq
        string result = "";
        while(pq.size() >= 2){
            // doing this twice to ensure not repeating
            P p1 = pq.top();
            pq.pop();
            
            P p2 = pq.top();
            pq.pop();
            
            result += p1.second;
            result += p2.second;
            
            p1.first--;
            p2.first--;
            
            if(p1.first > 0){
                pq.push(p1);
            }
            
            if(p2.first > 0){
                pq.push(p2);
            }
            
        }
        
        // finally if there is some element left in pq, we can safely add
        if(!pq.empty()){
            P p1 = pq.top();
            pq.pop();
            
            result += p1.second;
        }
        
        return result;
    }
};