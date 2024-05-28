class Solution {
public:
  
    // the nested thing is also possible
    // not just this - (){}[], but also this - ({[]}), ({})[]
    
    bool isOpening(char &ch){
        if(ch == '(' || ch == '{' || ch == '['){
            // is opening bracket
            return true;
        }
        return false;
    }
    
    char openCloseMapping(char &ch){
        if(ch == '}') return '{';
        if(ch == ')') return '(';
        if(ch == ']') return '[';
        
        return '.';
    }
    
    bool isValid(string s) {
        int n = s.length();
        stack<char> st;
        
        char ch, opening;
        for(int i = 0; i < n; i++){
            ch = s[i];
            if(isOpening(ch) == true){
                // simply push into stack
                st.push(ch);
            }else{
                // is a closing bracket
                // find corresponding opening -> in the stack
                // if the opening we found, not actual opening, can return false
                opening = openCloseMapping(ch);
                if(st.empty()){
                    return false;
                }
                if(opening != st.top()){
                    return false;
                }
                st.pop();
            }
        }
        
        if(!st.empty()){
            // there are some openings in the stack for which there are no closing
            return false;
        }
        
        // all are valid
        return true;
    }
};