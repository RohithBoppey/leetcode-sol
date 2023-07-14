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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL || head == NULL || k == 0){
            // cannot do anything
            return head;
        }
        
        // we need to find the count
        
        ListNode* temp = head, *last;
        
        int count = 0;
        
        while(temp != NULL){
            
            count++;
            
            last = temp;
            temp = temp->next;
        }
        
        // last would be pointing to the last element now
        
        last->next = head;
        
        // circular has been done
        
        // we need to break the find the n % k element and break the link
        
        k = k % count;
        int c = 0, t = count - k - 1;
        
        temp = head;
        
        while(c != t){
            c++;
            temp = temp->next;
        }
        
        // now temp would be pointing to the n - k element
        
        // assinging new head
        head = temp->next;
        
        // breaking the bond
        temp->next = NULL;
        
        return head;
        
    }
};