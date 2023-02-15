class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        int sum = 0, carry = 0;
        for(int i = n - 1; i >= 0; i--){
            sum = num[i] + (k % 10) + carry;
            num[i] = sum % 10;
            carry = sum / 10;
            k = k / 10;
            // if(k == 0){
            //     break;
            // }
        }
        
        while(k > 0){
            sum = (k % 10) + carry;
            carry = sum / 10;
            num.insert(num.begin(), sum % 10);
            k = k / 10;
        }
        
        if(carry == 1){
            num.insert(num.begin(), 1);
        }
        
        return num;
    }
};