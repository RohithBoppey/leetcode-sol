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