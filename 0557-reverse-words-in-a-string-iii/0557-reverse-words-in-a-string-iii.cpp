class Solution {
public:
    
    void reverse(string &s, int i, int j){
        int n = j - i + 1;
        if(n == 1){
            return;
        }
        for(int k = 0; k < n / 2; k++){
            swap(s[i + k], s[i + n - k - 1]);
        }
    }


    string reverseWords(string s){
        int n = s.size();
        // find words and then do
        int i = 0, j = 0;
        while(j < n){
            if(s[j] != ' '){
                // not a space so traverse
                j++;
            }else{
                reverse(s, i, j - 1);
                i = j + 1;
                j++;
            }
        }
        reverse(s, i, n - 1);
        
        return s;
    }

};