class Solution {
public:
    stack<int> st;
    vector<int> v;
    int n;
    
    vector<int> asteroidCollision(vector<int>& asteroids) {
        // if they move in the same direction, direct stack
        // or else go on until they get blasted
        // 1 means right, -1 means left
        n = asteroids.size();
        int t, c, blast;
        for(int i = 0; i < n; i++){
            c = asteroids[i];
            if(st.empty()){
                st.push(c);
            }else{
                t = st.top();
                if(t > 0 && c < 0){
                    // top is going right & current is left
                    // then they are colliding
                    while(!st.empty() && st.top() < abs(c) && st.top() > 0){
                        st.pop(); 
                    }
                    if(st.empty() || st.top() < 0){
                        st.push(c);
                    }else{
                        if(st.top() == abs(c)){
                            st.pop();
                        }
                    }
                }
                else {
                    // both in one direction
                    // either left or right
                    st.push(c);
                }
            }
        }
        
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        
        reverse(v.begin(), v.end());
        
        return v;
    }
};