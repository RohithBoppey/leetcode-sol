/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/


Node* mergeTwoLinkedLists(Node* l1, Node* l2){
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    
    // now we need to properly merge
    
    // using with extra space
    
    Node* head = new Node(0);
    Node* temp;
    
    temp = head;    
    
    while(l1 != NULL && l2 != NULL){
        if(l1->data < l2->data){
            // we need to assign l1
            // to the bottom
            
            temp->bottom = l1;
            temp = temp->bottom;
            l1 = l1->bottom;
            
        }else{
            // we need to assign l2
            
            temp->bottom = l2;
            temp = temp->bottom;
            l2 = l2->bottom;
        }
    }
    
    // assign the rest
    
    if(l1 == NULL) temp->bottom = l2;
    if(l2 == NULL) temp->bottom = l1;
    
    return head->bottom;
    
}


/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   // Your code here
   
   // connecting via bottom ✅; not side by side ❌;
   
   // base case check
   if(root == NULL || root->next == NULL){
       // either there is no element 
       // or there is a single element
       
       return root;
   }
   
   // immeditealy call for next
   
   Node* newResult = flatten(root->next);
   
   root->next = NULL;
   
   // forming / merging with the new one
   
   
   root = mergeTwoLinkedLists(root, newResult);
   
   
   return root;
   
}