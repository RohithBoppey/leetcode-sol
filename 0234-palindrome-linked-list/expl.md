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
        
![img](https://gist.github.com/assets/73538974/409f2005-1ed4-4664-9b9a-b95aa56d67a9)        
        
OTHER INTUITION USING STACK (THE SAME CAN BE DONE USING ARRAY AS WELL) : 

```
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        // we can push the first half in stack and then compare with the second half
        stack<int> st;
        
        // guess we need to find the length as well
        ListNode* l = head;
        int n = 0;
        while(l != NULL){
            n++;
            l = l->next;
        }
        
        // using the concept of fast, slow pointers to find the middle element
        ListNode* slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL){
            st.push(slow->val);
            slow = slow->next;
            fast = fast->next->next;
        }
        
        
        // since there is a middle element, it is not needed if the length is odd, hence we move a step
        if(n % 2 == 1){
            // odd
            slow = slow->next;
        }
        
        // when the loop quits, slow must be pointing to the middle element
        // so compare the ones from right to the stack contents
        while(!st.empty()){
            if(st.top() != slow->val){
                // un equal elements
                return false; 
            }
            st.pop();
            slow = slow->next;
        }
        
        // if reached here, stack is empty & slow went to right and first half reversed == second half from left to right
        return true;
    }
};
```
        
TC: FOR FINDING LENGTH = O(N) & PUSHING SLOW = O(N) ~ O(N)
BUT CAN WE DO IT WITHOUT FINDING LENGTH OR ANYTHING LIKE THAT?
        
YES, FASTEST SOLUTION:         
THIS WORKS SIMILARLY, BUT INSTEAD OF CACHING THE FIRST HALF, WE CAN REVERSE THE SECOND HALF, AND JUST COMPARE FIRST AND SECOND HALVES. WE NEED NOT FIND LENGTH AS WELL!!! BETTER     
        
```
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        if(head == NULL || head->next == NULL){
            // 0 elements or 1 element
            // no point in reversing
            return head;
        }

        // I will use 3 pointers to reverse
        ListNode* curr = head, *prev = NULL, *n;

        while(curr != NULL){
            n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }

        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        // the main problem is reversing right, so when we find the middle element, we can actually reverse the right half, and then compare the first and reversed second half
        
        // so now, we need to find the middle element
        ListNode *slow = head, *fast = head, *s, *r;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        // when this loop breaks, slow points to middle element, so reverse second half
        s = reverse(slow);
        r = head;
        
        // s = second half reversed, r = from first
        // we need to compare until end
        while(s != NULL){
            if(s->val != r->val){
                return false;
            }
            s = s->next;
            r = r->next;
        }
        
        // is a palindrome
        return true;
    }
};
```
