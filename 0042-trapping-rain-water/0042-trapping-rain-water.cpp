class Solution {
public:
    int trap(vector<int>& height) {
        
        // depends on left max and right max
        
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);
        
        // populating left and right
        
        int totalWater = 0;
        
        // left
        left[0] = height[0];
        for(int i = 1; i < n; i++){
            left[i] = max(left[i - 1], height[i]);
        }
        
        // right
        right[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; i--){
            right[i] = max(right[i + 1], height[i]);
        }
        
        // constrained by min
        int water = 0;
        for(int i = 0; i < n; i++){
            water = min(left[i], right[i]) - height[i];
            totalWater += water;
        }
        
        return totalWater;
        
    }
};