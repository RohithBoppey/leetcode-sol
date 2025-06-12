class Solution {
public:
    stack<int> st;

    int calPoints(vector<string>& operations) {
        int a, b;
        for(auto &op: operations){
            if(op == "C"){
                // remove
                st.pop();
            }else if(op == "D"){
                // double the last score
                a = st.top();
                st.push(2 * a);
            }else if(op == "+"){
                // remove 2 scores and add them and insert 
                a = st.top();
                st.pop();
                b = st.top();
                st.push(a);
                st.push(a + b);
            }else{
                // is an integer
                st.push(stoi(op));
            }
        }

        // now find sum and return
        int sum = 0;
        while(!st.empty()){
            a = st.top();
            st.pop();
            sum += a;
        }

        return sum;
    }
};