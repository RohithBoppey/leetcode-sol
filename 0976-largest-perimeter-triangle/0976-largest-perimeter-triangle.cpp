class Solution {
public:
    
    int isATriangle(int a, int b, int c){
        if(a + b > c && a + c > b && c + a > b){
            return true;
        }
        return false;
    }
    
    
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        // from the sliding window approach
        // keep going left until you find the max first
        
        int perimeter = 0;
        
        int start = n - 3;
        
        while(start >= 0){
            if(isATriangle(nums[start], nums[start + 1], nums[start + 2])){
                // then is a triangle
                perimeter = nums[start] + nums[start + 1] + nums[start + 2];
                break;
            }
            start--;
        }
        
        return perimeter;
    }
};