optimal approach:           

![WhatsApp Image 2023-07-13 at 15 28 46](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/9a90af02-5385-44b4-b478-4407cbd60ced)

this approach includes fixing one pointer in a loop (i) but ensure that it is not repeating, same with low and high     
when low + high + i index result in 0, we have found our pair       
after that, move low and high accordingly which is not repeating

![WhatsApp Image 2023-07-05 at 16 41 26](https://user-images.githubusercontent.com/73538974/251131823-568f9ae4-0f5c-45e4-bb68-64beeaaf851e.jpg)
            
![WhatsApp Image 2023-07-05 at 16 41 27](https://user-images.githubusercontent.com/73538974/251131862-64c20ccc-f4a9-4982-b613-e5b90388c896.jpg)

OPTIMAL CODE:
```
vector<vector<int>> threeSum(vector<int>& nums) {
        // using the most optimal approach
        // fixing one index and using the concept of low and high
        
        int n = nums.size();
        vector<vector<int>> result;
        
        int low, high, target;
        
        vector<int> triplet(3);
        
        sort(begin(nums), end(nums));
        
        for(int i = 0; i < n - 2; i++){
            // i is the fixed index
            
            // first need to verify whether the i is unique
            if(i == 0 || (i > 0 && nums[i] != nums[i - 1])){
                // means that the index i is unique
                low = i + 1;
                high = n - 1;
                
                // we are trying to find target = - (nums[i]);
                target = 0 - nums[i];
                
                // we need to find target
                while(low < high){
                    if(nums[low] + nums[high] == target){
                        // we have found the index
                        triplet[0] = nums[low];
                        triplet[1] = nums[high];
                        triplet[2] = nums[i];
                        
                        result.push_back(triplet);
                        triplet.resize(3, 0);
                        
                        // now that we have found the valid one
                        // move to the one which is not repeating
                        
                        while(low < high && nums[low] == nums[low + 1]) low++;
                        while(low < high && nums[high] == nums[high - 1]) high--;
                        low++;
                        high--;
                    }
                    else if(nums[low] + nums[high] < target){
                        low++;
                    }else{
                        high--;
                    }
                    
                }
            }
        }
        
        return result;
    }
```
