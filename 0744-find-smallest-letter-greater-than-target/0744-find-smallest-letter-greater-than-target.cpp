class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        // given letters are sorted - ascending
        
        for(auto x: letters){
            if(x - '0' > target - '0'){
                // first greater found
                return x;
            }
        }
        
        return letters[0];
    }
};