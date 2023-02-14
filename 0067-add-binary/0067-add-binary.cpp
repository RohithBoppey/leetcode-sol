class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size(), n = b.size();
        string res = "";
        int i = 0, j = 0, sum = 0, carry = 0;
        while(i < m && j < n){
            sum = (a[m - i - 1] - '0') + (b[n - j - 1] - '0') + carry;
            // cout << sum << endl;
            carry = sum / 2;
            res.push_back(sum % 2 + '0');
            i++;
            j++;
        }
        
        while(i < m){
            sum = (a[m - i - 1] - '0') + carry;
            // cout << sum << endl;
            carry = sum / 2;
            res.push_back(sum % 2 + '0');
            i++;
        }
        
        while(j < n){
            sum = (b[n - j - 1] - '0') + carry;
            // cout << sum << endl;
            carry = sum / 2;
            res.push_back(sum % 2 + '0');
            j++;
        }
        
        if(carry == 1){
            res += '1';
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};