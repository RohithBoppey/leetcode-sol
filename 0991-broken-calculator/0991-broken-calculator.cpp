class Solution {
public:
    int brokenCalc(int start, int target) {
        
        if(start >= target){
            // we are just adding 1 to target for n number of steps
            // example: start: 23 target: 17 -> required 6 +1's or -1's
            return (start - target);
        }
        
        // recursively divide the number whenever it is possible
        // else add 1
        
        if(target % 2 == 0){
            // even
            return 1 + brokenCalc(start, target / 2);
        }
        else{
            // odd
            return 1 + brokenCalc(start, target + 1);
        }
        
        // dummy
        return -1;
        
    }
};