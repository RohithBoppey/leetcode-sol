class Solution {
public:
    int last(int a){
        // gives last bit
        return a % 2;
    }
    
    int minBitFlips(int start, int goal) {
        int count = 0;
        int ls, lg;
        while(start != 0 || goal != 0){
            // keeps on looping until both are 0
            ls = last(start);
            lg = last(goal);
            if(ls != lg){
                count++;
            }
            start = start >> 1;
            goal = goal >> 1;
        }
        return count;
    }
};