class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // optimal - O(N) time
        
        // no sorting
        
        // using set to skip duplicates
        int n = nums.size();
        if(n == 0){
            return 0;
        }
        
        unordered_set<int> st;
        
        // insertion into set
        for(auto x: nums){
            st.insert(x);
        }
        
        // for each element find if that is the starting element of the sequnce
        
        int count = 1, maxCount = 1, curr = 0;
        
        for(int i = 0; i < n; i++){
            // find if it is the starting element
            // means prev doesnt exist
            if(st.find(nums[i] - 1) == st.end()){
                // doesnt exist
                // starting of the sequence
                // find the rest
                
                count = 1;
                curr = nums[i];
                
                while(st.find(curr + 1) != st.end()){
                    count++;
                    curr++;
                }
                
                // now we found sequence length
                maxCount = max(maxCount, count);
            }
        }
        
        
        return maxCount;
    }
};



