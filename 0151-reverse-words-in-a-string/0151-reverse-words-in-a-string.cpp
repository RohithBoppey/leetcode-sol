class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string res = "";
        stack<char> st;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] != ' '){
                st.push(s[i]);
            }
            if(i == 0){
                while(!st.empty()){
                    res += st.top();
                    st.pop();
                }
            }else if(!st.empty() and s[i] == ' '){
                while(!st.empty()){
                    res += st.top();
                    st.pop();
                }
                res += ' ';
            }
        }
        
        if(res[res.size() - 1] == ' '){
            res.pop_back();
        }
        
        if(res.empty()){
            return s;
        }
        
        return res;
    }
};