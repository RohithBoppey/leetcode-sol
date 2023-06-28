class Solution {
public:
    double myPow(double x, int n) {
        // the idea is to manipulate the powers
        int isNeg = (n < 0);
        long long n1 = n;
        if(isNeg == true){
            // turning n into positive
            n1 = n1 * -1;
        }
        
        double ans = 1.0;
        
        while(n1 > 0){
            if(n1 % 2 == 0){
                // is even
                x = x * x;
                n1 = n1 / 2;
            }else{
                // is odd
                ans = ans * x;
                n1--;
            }
        }
        
        if(isNeg == true){
            // is negative
            ans = (double) 1.0 / (double) ans;
        }
        
        return ans;
    }
};