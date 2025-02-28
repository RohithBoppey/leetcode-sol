class Solution {
public:

    string solve(string& text1, string& text2) {
        // take the len * len array
        int n1 = text1.size();
        int n2 = text2.size();

        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));

        string s = "";

        // processing
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if(text1[i - 1] == text2[j - 1]){
                    // must take in the subsequence
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }else{
                    // go in the direction of max
                    int first, second;
                    first = dp[i - 1][j];
                    second = dp[i][j - 1];

                    dp[i][j] = max(first, second);
                }
            }
        }


        // backtrack from the DP array to select the string elements
        // should consider all elements
        int i = n1, j = n2;
        while(i > 0 && j > 0){
            if(text1[i - 1] == text2[j - 1]){
                // choose it
                s += text1[i - 1];
                i--;
                j--;
            }
            else{
                // choose the max direction in which we came down
                // so here only 2 cases are there
                // you go left, or you go right
                if(dp[i - 1][j] > dp[i][j - 1]){
                    s += text1[i - 1];
                    i--;
                }else{
                    s += text2[j - 1];
                    j--;
                }
            }
        }

        // there could be remaining letters in s1 and s2 as well
        while(i > 0){
            s += text1[i - 1];
            i--;
        }

        while(j > 0){
            s += text2[j - 1];
            j--;
        }

        reverse(s.begin(), s.end());
        return s;
    }

    string shortestCommonSupersequence(string str1, string str2) {
        
        string common = solve(str1, str2);
        if(common.length() == 0){
            return str1 + str2;
        }

        return common;

    }

};