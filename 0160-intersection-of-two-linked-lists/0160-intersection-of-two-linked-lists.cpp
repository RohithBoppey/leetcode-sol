/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // without the use of count
        
        // since no count, we need to keep reassigning
        
        ListNode *t1 = headA, *t2 = headB;
        
        
        while(t1 != t2){
            
            // they can be null and then should be reassigned
            
            
            if(t1 == NULL) {
                t1 = headB;
            }else{
                t1 = t1->next;
            }
            
            
            if(t2 == NULL){
                t2 = headA;
            }else{
                t2 = t2->next;
            }
            
            
        }
        
        // here the loop breaks
        // only when t1 == t2 and they are some node or null
        
        return t1;
        
        
    }
};







