class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0, j = needle.size(), n = haystack.size();
        while(j <= n){
            int flag = 0, t = 0;
            for(int k = i; k < j; k++){
                if(haystack[k] != needle[t]){
                    flag = 1;
                    // cout << "n" << endl;
                    break;
                }
                t++;
            }
            if(flag == 0){
                return i;
            }
            t = 0;
            i++;
            j++;
        }
        return -1;
    }
};