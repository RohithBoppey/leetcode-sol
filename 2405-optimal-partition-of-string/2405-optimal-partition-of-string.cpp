class Solution {
public:
    int partitionString(string s) {
        int count = 1;
        unordered_set<char> set;
        for(auto ch: s){
            if(set.find(ch) != set.end()){
                set.clear();
                count++;
            }
            set.insert(ch);
        }
        return count;
    }
};