class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> missing(2001, 1);
        for(int i = 0; i < n; i++){
            missing[arr[i]] = 0;
        }
        int i = 1;
        while(k != 0){
            if(missing[i] != 0){
                // missing
                k--;
                if(k == 0){
                    break;
                }
            }
            i++;
        }
        
        return i;
    }
};