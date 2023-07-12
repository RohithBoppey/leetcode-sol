//{ Driver Code Starts
#include <bits/stdc++.h>

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

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}

// } Driver Code Ends


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

