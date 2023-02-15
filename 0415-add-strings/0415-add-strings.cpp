class Solution {
public:
    string addStrings(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        int i = 0, j = 0;
        string res = "";
        int sum = 0, carry = 0;
        while(i < m && j < n){
            sum = (num1[m - i - 1] - '0') + (num2[n - j - 1] - '0') + carry;
            carry = sum / 10;
            res.push_back(sum % 10 + '0');
            i++;
            j++;
        }
        
        while(i < m){
            sum = num1[m - i - 1] - '0' + carry;
            res.push_back(sum % 10 + '0');
            carry = sum / 10;
            i++;
        }
        
        while(j < n){
            sum = num2[n - j - 1] - '0' + carry;
            res.push_back(sum % 10 + '0');
            carry = sum / 10;
            j++;
        }
        
        // cout << carry << endl;
        
        if(carry != 0){
            res.push_back(carry + '0');
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};