class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int j = 0;
        for(int i = 1; i <= 1000 && j < arr.size(); i++){
            if(arr[j] == i){
                j++;
            }else{
//                 missing
                k--;
                if(k == 0){
                    return i;
                }
            }
        }
        
        return arr[arr.size() - 1] + k;
    }
};