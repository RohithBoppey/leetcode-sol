Short explanation: 
- for the moore's voting algo problem, [the first one](https://leetcode.com/problems/majority-element/description/), when we say the min count required is: n / 2, meaning at max, only a single element can occur.
- also all the other elements which are repeating k times (k is a random number), it gets cancelled by the other numbers
- so using basic moore's algo worked there since we are only dealing with one number.
- but when n / 3 is the min count, at max, we can see more than 1 number. like if n = 50, then 50 / 3 => 17. So there can exist 2 elements which can occur >= 17 times.
- at max, 2 elements can occur if n / 3 is the min amount required.
- so instead of maintaing a single val and count, I'll maintain 2-2
- and the 2 values should not be equal
- check the if conditions in the code once to understand

for n > 2
![image](https://user-images.githubusercontent.com/73538974/249562949-11ba2bc5-f253-4048-8f13-3a392fa9f08e.png)
​
since given there is only number that follows this, we can simply use moores algo
that is if an element exists k times there should exist other number for k times only, that way last one number would be left, that is our required number
but for that for n > 3, there is a small thing to notice, no matter the length, the max numbers could only be 2 (image)
![image](https://user-images.githubusercontent.com/73538974/249564089-09b650e0-ac82-43da-af22-5b6454f7520d.png)
​
so using this logic, we can have 2 counts and translate the same, but making sure that those 2 elements are not equal thats it and finally verify their counts.

```c++
class Solution {
public:
    int n;
    vector<int> majorityElement(vector<int>& nums) {
        n = nums.size();

        int c1 = 0, c2 = 0, ele1 = INT_MAX, ele2 = INT_MAX;
        int val; 

        for(int i = 0; i < n; i++){
            val = nums[i];
            if(c1 == 0 && ele2 != nums[i]){
                // update the element1 with the new value
                c1 = 1;
                ele1 = nums[i];
            }else if(c2 == 0 && ele1 != nums[i]){
                c2 = 1;
                ele2 = nums[i];
            }
            // both elements are populated
            // so increase count now
            else if(ele1 == nums[i]){
                c1++;
            }else if(ele2 == nums[i]){
                c2++;
            }else{
                c1--;
                c2--;
            }
        }

        // now we have ele1 and ele2 ready
        // check counts
        vector<int> res;
        int count1 = 0, count2 = 0;

        for(auto &x: nums){
            if(x == ele1){
                count1++;
            }
            if(x == ele2){
                count2++;
            }
        }

        int req = (n / 3) + 1;

        if(count1 >= req) res.push_back(ele1);
        if(count2 >= req) res.push_back(ele2);

        return res;

    }
};
```
