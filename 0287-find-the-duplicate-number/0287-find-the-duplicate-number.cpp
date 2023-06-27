class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        // using the tortoise - hare approach
        // LINKED LIST cycle finding etc
        
        int slow, fast;
        
        // initialising
        slow = nums[0];
        fast = nums[0];
        
        // to find the first breaking point
        while(1){
            slow = nums[slow];
            fast = nums[nums[fast]];
            
            if(slow == fast){
                break;
            }
        }
        
        // now that loop exisits
        fast = nums[0];
        
        // find the loop start
        while(slow != fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        
        // they now point to loop start
        return slow;
        
    }
};