​ASKED IN : `yatra.com`    

Find all in : [here](https://github.com/RohithBoppey/leetcode-sol/blob/master/REPORTS/SLIDING%20WINDOW.md)  
  
PROCESS:    
      
![image](https://gist.github.com/assets/73538974/6f04a16c-9ec7-49d4-a8c4-3c941f2f7aaf)
    
WHENEVER NEW ELEMENT COMES IN J, WE MULTIPLY =>     
BUT THE LOGIC HERE IS THAT: WE ARE MISSING THE SUBARRAY OF THE NUMBER ITSELF =>  
    
![image](https://gist.github.com/assets/73538974/b1562d0d-ad2b-4fef-81a5-8ea56b6c0471)
![image](https://gist.github.com/assets/73538974/de893a84-b104-40e8-9287-90356bdf8e87)
![image](https://gist.github.com/assets/73538974/524cbfea-d19f-4961-b449-6ff2f2b5d848)
![image](https://gist.github.com/assets/73538974/7f13a7ff-5a97-4ce5-9b56-3b4fa2dfce3e)
      
```
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // all are positives => contains no 0
        // so if k = 0 => then there will be no subarray that can give us a number less than zero
        if(k == 0 || k == 1){
            return 0;
        }
        
        long long int pr = 1;
        int ans = 0;
        
        int i = 0, j = 0, n = nums.size();
        
        while(j < n){
            
            // taking in j like in SLIDING WINDOW CONCEPT
            pr *= nums[j];
              
            // at the end of each iteration, we can check here
            // until it is greater we can keep pushing i
            while(pr >= k){
                pr = pr / nums[i]; 
                i++;
            }
            
            // once pushing i is done
            // we gotta add - ALL SUBARRAYS ENDING AT index - j
            ans += j - i + 1;
            
            // take the second number
            j++;
        }
        
        return ans;
    }
};
```
