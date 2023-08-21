class Solution {
public:
    
    void findFactors(int n, vector<int>& factors){
        int a, b;
        factors.push_back(1);
        for(int i = 2; i <= sqrt(n); i++){
            if(n % i == 0){
                // is divisble, check for square root
                a = i;
                b = n / i;
                factors.push_back(a);
                if(a != b){
                    factors.push_back(b);
                }
            }
        }
    }
    
    void printVector(vector<int>& v){
        for(auto x: v){
            cout << x << " ";
        }
        cout << endl;
    }
    
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        if(n == 1){
            // cannot form a substring
            return false;
        }
        // should find factors for the length now
        vector<int> factors;
        findFactors(n, factors);
        // printVector(factors);
        // for each factor, check if all the strings are same
        int fa, j;
        for(int i = 0; i < factors.size(); i++){
            fa = factors[i];
            j = fa;
            for(; j < n; j++){
                if(s[j] != s[j % fa]){
                    break;
                }
            }
            // here it either breaks or the loop is done
            // if loop is done, that means it is true
            if(j == n){
                return true;
            }
        }
        return false;
    }
};