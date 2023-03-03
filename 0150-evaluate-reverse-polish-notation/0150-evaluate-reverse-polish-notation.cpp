class Solution {
public:
    
    bool isSymbol(string ch){
        return (ch == "+") || (ch == "-") || (ch == "*") || (ch == "/");
    }
    
    string evaluate(int a, int b, string symbol){
        int ans = 0;
        if(symbol == "+"){
            ans = a + b;
        }else if(symbol == "-"){
            ans = a - b;
        }else if(symbol == "*"){
            ans = a * b;
        }else{
            ans = a / b;
        }
        return to_string(ans);
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(auto ch: tokens){
            if(isSymbol(ch)){
//                 pop twice , operateand push the result char
                string a = st.top();
                st.pop();
                string b = st.top();
                st.pop();
                string result = evaluate(stoi(b), stoi(a), ch);
                st.push(result);
            }else{
                st.push(ch);
            }
        }
    int ans = stoi(st.top());
    return ans;
    }
    
};