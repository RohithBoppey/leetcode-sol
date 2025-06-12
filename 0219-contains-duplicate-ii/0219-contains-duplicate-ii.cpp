class Solution {
public:
    int n;
    unordered_map<int, int> mp;

    int ws(int &i, int& j){
        return j - i + 1;
    }

    int ms(){
        return mp.size();
    }

    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // sliding window solution
        int i = 0, j = 0;
        n = nums.size(); 

        while(j < n){
            mp[nums[j]]++;
            
            if(ws(i,j) == ms()){
                // all are unique, nothing is repeating
            }else{ 
                // some element is repeating
                while(i <= j && ws(i, j) != ms()){
                    // remove from behind
                    if(nums[i] == nums[j] && abs(j - i) <= k){
                        // such element found
                        return true;
                    }
                    mp[nums[i]]--;
                    if(mp[nums[i]] == 0){
                        mp.erase(nums[i]);
                    }
                    i++;
                }
            }
            j++;
        }

        return false;

    }
};