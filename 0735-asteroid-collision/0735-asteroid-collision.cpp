class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        
        // using stacks
        
        int n = asteroids.size();
        
        if(n == 0 || n == 1){
            return asteroids;
        }
        
        
        stack<int> st;
        
        
        for(int i = 0; i < n; i++){
            
            if(st.empty()){
                
                // no choice but to retain
                st.push(asteroids[i]);
                
            }
            
            else{
                
                // check if our number is -ve
                if(asteroids[i] < 0){
                    
                    // negative
                    // check upto where it can go
                    
                    bool flag = true;
                    
                    while(!st.empty() && st.top() > 0 && st.top() <= abs(asteroids[i])){
                        
                        // the number is positive
                        // and less than the current asteroid size
                        
                        if(st.top() == abs(asteroids[i])){
                            flag = false;    
                        }
                        st.pop();
                        
                        if(flag == false){
                            break;
                        }
                        
                    }
                    
                    if(flag == false){
                        continue;
                    }
                    
                    if(st.empty()){
                        
                        // the current asteroid has cleared all
                        // hence need to be retained
                        st.push(asteroids[i]);
                        
                    }
                    else{
                        
                        // stack is not empty
                        if(st.top() < 0){
                            
                            // negative
                            // so we can add it
                            st.push(asteroids[i]);
                        }
                        
                    }
                    
                }
                
                else{
                    // positive
                    // so we can directly add
                    st.push(asteroids[i]);
                    
                }
            }
            
        }
        
        // adding the stack elements into the array
        vector<int> res;
        
        int t;
        
        while(!st.empty()){
            t = st.top();
            st.pop();
            res.push_back(t);
        }
        
        reverse(res.begin(), res.end());
        
        return res;
        
    }
};