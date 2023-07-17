class Solution {
public:
    int minNumberOfFrogs(string s) {
        
        
        int n = s.size(); // s is a mix of croak workds
        
        string req = "croak";
        
        vector<int> freq(5, 0); // this vector counts number of occurances
        
        int mx = 0, curr = 0; // no of frogs
        
        int currIndex;
        
        for(int i = 0; i < n; i++){
            
            currIndex = req.find(s[i]);
            
            // based on this current index, I will be finding out number of frogs and so on
            
            freq[currIndex]++;
            
            if(currIndex == 0){
                // means 'c' -> start of a new frog singing
                curr++;
                mx = max(mx, curr);
            }
            
            else if(currIndex == 4){
                // last index -> 'k', means frog has stopped singing
                freq[currIndex]--;
                curr--;
            }
            
            if(currIndex > 0){
                // at all times, we need to check whether the prev character has been sang or not
                freq[currIndex - 1]--;
                
                if(freq[currIndex - 1] < 0){
                    
                    // that means some letter occured without previous one
                    return -1;
                }
            }
            
        }
        
        // now if the frogs == 0 means all frogs sang properly
        return (curr == 0) ? mx : -1;
        
    }
};