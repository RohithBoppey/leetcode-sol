class Solution {
public:
    
    int n;
    stack<int> st;
    string res;
    
    string removeKdigits(string num, int k) {
        res = "";
        n = num.size();
        st = stack<int>();
        int t, c;
        
        for(int i = 0; i < n; i++){
            c = num[i] - '0';
            // stack is not empty
            while(!st.empty() && k > 0 && st.top() > c){
                st.pop();
                k--;
            }
            st.push(c);
        }
        
        
        // if there are any more remaining k, remove from top
        while(k > 0){
            st.pop();
            k--;
        }
        
        char ch;
        while(!st.empty()){
            ch = st.top();
            res += ch + '0';
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        
        // remove the start length of the array
        int i = 0;
        while(res[i] == '0'){
            i++;
        }
        n = res.size();
        // resize from the ith pos
        res = res.substr(i, n-i);
        
        return res.length() == 0 ? "0" : res;
    }
};