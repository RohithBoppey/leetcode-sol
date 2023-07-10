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
        // using the solution of count
        
        int c1 = 0, c2 = 0;
        
        // 2 pointers to traverse
        
        ListNode* t1 = headA, *t2 = headB;
        
        
        // finding the count
        
        while(t1 != NULL){
            c1++;
            t1 = t1->next;
        }
        
        
        while(t2 != NULL){
            c2++;
            t2 = t2->next;
        }
        
        
        // reasssign to head
        t1 = headA, t2 = headB;
        
        int n = abs(c1 - c2);
        
        if(c1 < c2){
            // reduce c2 by n steps
            while(n != 0){
                t2 = t2->next;
                n--;
            }
        }
        
        else{
            // reduce c1 by n steps
            while(n != 0){
                t1 = t1->next;
                n--;
            }
        }
        
        
        // now find if there is an intersection
        
        while(t1 != NULL && t2 != NULL && t1 != t2){
            t1 = t1->next;
            t2 = t2->next;
        }
        
        
        // now the loop breaks
        if(t1 == t2){
            return t1;
        }else{
            return NULL;
        }
        

    }
};