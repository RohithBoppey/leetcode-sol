class Solution {
public:
    // the idea is simple, for a current index
    // on the head, water is there or not depends on -> leftmax seen so far and rightmax seen so far
    int trap(vector<int>& height) {
        int n = height.size();
        int water = 0;
        vector<int> left(n, 0), right(n, 0);
        
        // populate left right
        left[0] = height[0];
        for(int i = 1; i < n; i++){
            left[i] = max(left[i - 1], height[i]);
        }
        
        right[n-1] = height[n-1];
        for(int i = n - 2; i >= 0; i--){
            right[i] = max(right[i + 1], height[i]);
        }
        
        int h, w;
        for(int i = 0; i < n; i++){
            h = min(left[i], right[i]) - height[i];
            w = 1;
            water += h * w;
        }
        
        return water;
    }
};