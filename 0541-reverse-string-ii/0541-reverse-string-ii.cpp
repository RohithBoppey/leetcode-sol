class Solution {
public:
    void reverse(string &s, int i, int j){
        int n = j - i + 1;
//         this is the window size
        if(n == 1){
            return;
        }
        for(int k = 0; k < n / 2; k++){
            swap(s[i + k], s[i + n - k - 1]);
        }
    }
    
    string reverseStr(string s, int k) {
        int n = s.size();
        // find words and then do
        int i = 0;
        for(i = 0; i < n; i += 2 * k){
            reverse(s, i, min(n - 1, i + k - 1));
        }
        // cout << i << " " << n << endl;
        return s;
    }
};