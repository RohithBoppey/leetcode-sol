class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int total = 0;

        for(int i = low; i <= high; i++){
            // iterating all numbers
            string s = to_string(i);
            int len = s.size();
            if (len % 2){
                // odd
                continue;
            }
            // compare first n / 2 and last n / 2
            int first = 0, last = 0, j = 0;

            while(j < len / 2){
                first += s[j] - '0';
                last += s[len - j - 1] - '0';
                j++;
            } 

            if(first == last) total++;
        }

        return total;
    }
};