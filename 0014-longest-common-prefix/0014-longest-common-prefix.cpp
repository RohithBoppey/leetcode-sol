class Solution {
public:
    bool allMatched(vector<string>& strs, int mid){
        // for all the strings, check from start to mid characters
        for(int i = 1; i < strs.size(); i++){
            for(int j = 0; j < mid; j++){
                // checking till j characters
                if(strs[i][j] != strs[0][j]){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    
    string longestCommonPrefix(vector<string>& strs) {
        // this solution uses binary search
        
        // we are using the binary search to find the max length upto which the prefix is same
        
        int low = 0, high = INT_MAX, sz;
        for(auto &s: strs){
            sz = s.length();
            high = min(high, sz);
            // checking min should be enough
        }
        
        int mid;
        
        int ans = 0;
        
        // using binary search from low to high
        while(low <= high){
            mid = low + (high - low) / 2;
            if(allMatched(strs, mid) == true){
                // all the characters matched
                ans = mid;
                low = mid + 1;
            }else{
                // did not match
                // so converse
                high = mid - 1;
            }
        }
        
        
        return strs[0].substr(0, ans);
        
    }
};