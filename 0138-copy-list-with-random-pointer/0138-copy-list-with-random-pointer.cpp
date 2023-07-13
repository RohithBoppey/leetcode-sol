/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        // using hashmap to hash the pointers
        
        Node* temp = head;
        
        unordered_map<Node*, Node*> mp;
        
        while(temp != NULL){
            // create a new copy of it
            
            Node* copy = new Node(temp->val, NULL, NULL);
            mp[temp] = copy;
            temp = temp->next;
        }
        
        // now copy is created
        // nowe re assign based on that
        
        temp = head;
        
        while(temp != NULL){
            mp[temp]->next = mp[temp->next];
            mp[temp]->random = mp[temp->random];
            
            temp = temp->next;
        }
        
        return mp[head];
        
    }
};




