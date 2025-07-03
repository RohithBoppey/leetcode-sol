class Solution {
public:

    stack<int> st; 

    int process(string& curr, int a, int b){
        if(curr == "+") return a + b;
        if(curr == "-") return b - a;
        if(curr == "*") return a * b;
        if(curr == "/") return b / a;
        
        return 0;
    }

    int evalRPN(vector<string>& tokens) {
        int res = 0;
        string curr = "";
        
        int n = tokens.size(); 

        int a, b;
        for(int i = 0; i < n; i++){
            curr = tokens[i];
            if(curr == "+" || curr == "-" || curr == "/" || curr == "*"){
                // pop 2 and push back
                a = st.top();
                st.pop();
                b = st.top();
                st.pop();

                int p = process(curr, a, b);

                st.push(p);
            }else{
                // must be a number
                st.push(stoi(curr));
            }
        }

        res = st.top();
        return res; 
    }
};