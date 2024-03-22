/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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