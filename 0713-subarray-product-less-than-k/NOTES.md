​ASKED IN : `yatra.com`    

Find all in : [here](https://github.com/RohithBoppey/leetcode-sol/blob/master/REPORTS/SLIDING%20WINDOW.md)  
  
PROCESS:    
  
![image](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/a8d052b5-37d0-4cef-a059-661f4b40133c)    
  
WHENEVER NEW ELEMENT COMES IN J, WE MULTIPLY =>     
BUT THE LOGIC HERE IS THAT: WE ARE MISSING THE SUBARRAY OF THE NUMBER ITSELF =>  
    
![image](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/67b152f0-af0d-4294-aba0-6d90c7839fb6)
![image](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/6f17dea2-5a22-4673-abe2-f450e26a6cab)
![image](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/5ac5d51b-ae3b-4522-baa1-5ad9a37ccb1b)
![image](https://github.com/RohithBoppey/leetcode-sol/assets/73538974/c9cb1770-019c-48e4-be3e-f3827d6b06e9)
      
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
