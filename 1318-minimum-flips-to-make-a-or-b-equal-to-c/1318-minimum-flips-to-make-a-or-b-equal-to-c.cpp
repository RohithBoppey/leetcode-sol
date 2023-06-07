class Solution {
public:
    int lastBit(int a){
        // either 0 or 1
        return a % 2;
    }
    
    int minFlips(int a, int b, int c) {
        // checking the last bit and then changing as required
        int count = 0;
        int lba, lbb, lbc;
        while(c != 0 || b != 0 || a != 0){
            // cout << a << " " << b << " " << c << endl;
            
            // find the last bits
            lba = lastBit(a);
            lbb = lastBit(b);
            lbc = lastBit(c);
            
            // cout << lba << " " << lbb << " " << lbc << endl;
            
            if(lbc == 0){
                // if result is 0, then both must be zero
                if(lba == 1){
                    count += 1;
                }
                if(lbb == 1){
                    count += 1;
                }
            }else{
                // lbc = 1
                if(lba == 0 && lbb == 0){
                    // need to change atleast 1
                    count += 1;
                }
            }
            
            a = a >> 1;
            b = b >> 1;
            c = c >> 1;
        }
        return count;
    }
};