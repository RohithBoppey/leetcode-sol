/*
 * Definition for linked list.
 * class Node {
 *  public:
 *		int data;
 *		Node *next;
 * 		Node *child;
 *		Node() : data(0), next(nullptr), child(nullptr){};
 *		Node(int x) : data(x), next(nullptr), child(nullptr) {}
 *		Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
 * };
 */

Node* mergeTwoLists(Node* a, Node* b) {
    
    Node *temp = new Node(0);
    Node *res = temp; 
    
    while(a != NULL && b != NULL) {
        if(a->data < b->data) {
            temp->child = a; 
            temp = temp->child; 
            a = a->child; 
        }
        else {
            temp->child = b;
            temp = temp->child; 
            b = b->child; 
        }
    }
    
    if(a) temp->child = a; 
    else temp->child = b; 
    
    return res -> child; 
    
}


Node* flattenLinkedList(Node* root) 
{
	if (root == NULL || root->next == NULL) 
            return root; 
  
        // recur for list on right 
        Node* l2 = flattenLinkedList(root->next); 

		root->next = NULL;

        // now merge 
        root = mergeTwoLists(root, l2); 
  
        // return the root 
        // it will be in turn merged with its left 
        return root; 
}
