class Solution {
public:
    int arraySign(vector<int>& nums) {
        int neg = 0;
        for(auto x: nums){
            if(x < 0){
                neg++;
            }else if(x == 0){
//                 x = 0, product itself is 0
                return 0;
            }
        }
        
        return (neg % 2 == 0) ? 1 : -1;
    }
};