​BRUTEFORCE SOLUTION: -------- 
    
CONVERT INTO ARRAY & CHECK PALINDROME => SIMPLE LOOPING CONCEPT   
    
```
class Solution {
public:
    
    bool checkArrayPalindrome(vector<int>& v){
        int n = v.size();
        for(int i = 0; i < n / 2; i++){
            if(v[i] != v[n - i - 1]){
                return false;
            }
        }
        return true;
    }
    
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        // pushing all into a vector and checking
        while(head != NULL){
            v.push_back(head->val);
            head = head->next;
        }
        return checkArrayPalindrome(v);
    }
};
```
