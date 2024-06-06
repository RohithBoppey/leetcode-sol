
BRUTE FORCE SOLUTION: --- (VERY SLOW) -> USING 2 FOR LOOPS (NESTED INDEX)

```c++
class Solution {
public:
    int n;
    int ms = INT_MIN, mn = INT_MAX;
    
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        n = nums.size();
        for(int i = 0; i < n; i++){
            ms = nums[i];
            mn = nums[i];
            for(int j = i; j < n; j++){
                ms = max(ms, nums[j]);
                mn = min(mn, nums[j]);
                ans += (ms - mn);
            }
        }
        return ans;
    }
};
```
    
+ This uses the idea of [Sum of Subarray minimums](https://leetcode.com/problems/sum-of-subarray-minimums/), but instead of just min => we do min & max and then subtract them
+ `Σ(max - min)` for every subarray can be translated. Can be combined.        
![WhatsApp Image 2024-06-06 at 21 22 08_ab8b8113](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/92cfaae1-276a-4c26-b75a-0a7a897a918c)        
        
```c++
class Solution {
public:
    
    int n;
    vector<int> left, right;
    // used to store number & count of numbers greater or lesser to the right or left
    stack<pair<int,int>> st;
    
    long long left_res, right_res, ans;
    
    void printV(vector<int>& v){
        for(auto c: v){
            cout << c << " ";
        }
        cout << endl;
    }
    
    void NSL(vector<int>& nums){
        st = stack<pair<int,int>>();
        // we need nearest smaller to left
        // so should proceed from left to right
        int count = 1, c;
        for(int i = 0; i < n; i++){
            count = 1;
            c = nums[i];
            while(!st.empty() && st.top().first > c){
                // we found a smaller element
                count += st.top().second;
                st.pop();
            }
            st.push({c, count});
            left[i] = count;
        }
    }
    
    void NSR(vector<int>& nums){
        st = stack<pair<int,int>>();
        int count = 1, c;
        for(int i = n - 1; i >= 0; i--){
            count = 1;
            c = nums[i];
            while(!st.empty() && st.top().first >= c){
                // we found a smaller element
                count += st.top().second;
                st.pop();
            }
            st.push({c, count});
            right[i] = count;
        }
    }
    
    void NGL(vector<int>& nums){
        st = stack<pair<int,int>>();
        // we need nearest smaller to left
        // so should proceed from left to right
        int count = 1, c;
        for(int i = n - 1; i >= 0; i--){
            count = 1;
            c = nums[i];
            while(!st.empty() && st.top().first < c){
                // we found a smaller element
                count += st.top().second;
                st.pop();
            }
            st.push({c, count});
            left[i] = count;
        }
    }
    
    void NGR(vector<int>& nums){
        st = stack<pair<int,int>>();
        // we need nearest smaller to left
        // so should proceed from left to right
        int count = 1, c;
        for(int i = 0; i < n; i++){
            count = 1;
            c = nums[i];
            while(!st.empty() && st.top().first <= c){
                // we found a smaller element
                count += st.top().second;
                st.pop();
            }
            st.push({c, count});
            right[i] = count;
        }
    }
    
    void calcMin(vector<int>& nums){
        left.resize(n, 0);
        right.resize(n, 0);
        NGL(nums);
        NGR(nums);
        // calc contribution of min now
        int c;
        for(int i = 0; i < n; i++){
            c = nums[i];
            left_res += (long long)(left[i] * right[i]) * c;
        }
    }
    
    void calcMax(vector<int>& nums){
        left.resize(n, 0);
        right.resize(n, 0);
        NSL(nums);
        NSR(nums);
        // calc contribution of max
        int c;
        for(int i = 0; i < n; i++){
            c = nums[i];
            right_res += (long long)(left[i] * right[i]) * c;
        }
    }
    
    long long subArrayRanges(vector<int>& nums) {
        n = nums.size();
        ans = 0;
        calcMin(nums);
        calcMax(nums);
        ans = left_res - right_res;
        return ans;
    }
};
```
​
