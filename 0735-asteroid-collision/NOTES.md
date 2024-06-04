![WhatsApp Image 2024-06-04 at 22 49 11_ae4908c2](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/510d9de0-314c-4e34-ac34-7ce99a2cfeae)

```
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
```

ASKED IN: **UBER LYFT**

TESTED ON TESTCASES:        
            
```
[5,10,-5]
[8,-8]
[10,2,-5]
[10,8,-8,5,2,-1,6,-3]
[10,4,3,2,1,-8]
[5,2,-3,8,-9,-1]
[-2,2,1,-2]
```            
                
INITIAL BACKTRACKING APPROACH: (PASSES ALL BUT SLOW AS HELL ✅):                

![image](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/e8b9fe52-08b3-470c-8370-ac482932d2af)
![image](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/5f52c8d1-9854-4b30-87dc-4c86db22279d)
![image](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/67762864-c981-4b81-a866-3bf45e164bf7)
​
```
class Solution {
public:
    
    void solve(vector<int>& nums, int n){
        
        if(n == 1 || n == 0){
            // no more operations needed
            return;
        }
        
        bool isCollision = false;
        
        int i = 0;
        
        while(i < n - 1){
            
            // check for collision
            if(nums[i] > 0 && nums[i + 1] < 0){
                // collision is there
                isCollision = true;
                
                // make the required change
                if(abs(nums[i]) < abs(nums[i + 1])){
                    
                    // remove ith element
                    // marking
                    nums[i] = 1001;
                }
                else if(abs(nums[i]) > abs(nums[i + 1])){
                    
                    // remove i + 1th element
                    nums[i + 1] = 1001;
                }
                else{
                    
                    // remove both the elements
                    nums[i] = 1001;
                    nums[i + 1] = 1001;
                    
                }
                
                // move the two indices
                i = i + 2;
                
            }
            
            else{
                i++;   
            }
            
        }
        
        if(isCollision == false){
            // all collisions are done
            return;
        }
        
        // remove the 1001 elements from the modified array
        
        i = 0;
        
        while(i < nums.size()){
            if(nums[i] != 1001){
                i++;
            }else{
                // else remove it
                nums.erase(nums.begin() + i);
            }
        }
        
        n = nums.size();
        
        solve(nums, n);
    }
    
    
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        
        if(n == 1 || n == 0){
            // no direciton, is safe always
            return asteroids;
        }
        
        solve(asteroids, n);
        
        return asteroids;
    }
};
```            
            
But it has been observed that we can solve the same problem using stacks!            
![WhatsApp Image 2023-07-20 at 16 24 55](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/8e8e7af2-ca6c-4c9c-a4f9-5b448f8eb2c2)            
![WhatsApp Image 2023-07-20 at 16 25 27](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/0feb1076-dc9c-447b-916e-11ca316cd2d1)            
            
```
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
                    
                    if(st.top() == abs(asteroids[i])){
                        // remove and continue
                        st.pop();
                        continue;
                    }
                    
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
```

