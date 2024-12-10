class Solution {
public:
    long a, b, c;

    int gcd(int x, int y) {
        // idea is that gcd(a,b) = gcd(b, a % b)
        while (y != 0) {
            int temp = y;
            y = x % y;
            x = temp;
        }
        return x;
    }

    long lcm(long x, long y) {
        return (x / gcd(x, y)) * y;
    }

    int findMagic(long k){
        // returns the number of numbers which are divisible by either a or b or c
        // using the concept of sets, we can solve this
        // A U B U C = a + b + c - (a^b) - (c^b) - (a^c) + (a^b^c)
        
        return (k / a) + (k / b) + (k / c) - (k / lcm(a,b)) - (k / lcm(a,c)) - (k / lcm(b,c)) + (k / lcm(lcm(a,c),b));
        
    }

    int nthUglyNumber(int n, int aa, int bb, int cc) {
        // somehow we should find out the number of magic number when a,b,c are provided. 
        
        a = (long) aa;
        b = (long) bb;
        c = (long) cc;

        long low = 1, high = 2e9, mid;

        while(low < high){
            mid = low + (high - low) / 2;
            int mg = findMagic(mid);

            if(mg >= n){
                // can reduce the search space
                high = mid;
            }else{
                // mg < n
                // must increase the search space
                // go right
                low = mid + 1; 
            }

        }

        return low;

    }
};