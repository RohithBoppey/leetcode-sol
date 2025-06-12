class Solution {
public:
    int countOnes(int n){
        if(n <= 1){
            // 1 bit is there
            return n;
        }
    
        // populate
        int rem = n % 2;
        return rem + countOnes(n / 2);
    }

    int hammingWeight(int n) {
        return countOnes(n);
    }
};