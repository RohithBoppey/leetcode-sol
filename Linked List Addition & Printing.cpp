//#include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <math.h>

#define pb push_back
#define ll long long int

using namespace std;

/*-------------------------------------------
--------------Rohith's Solution--------------
---------------------------------------------*/

#define maxX(a,b) (a>b?a:b)
#define minX(a,b) (a<b?a:b)
#define isEven(a) ((a%2==0)?1:0)
#define isOdd(a) ((a%2==0)?0:1)
#define isNeg(a) ((a<0)?1:0)
#define loop(n) for(int i = 0; i < n; i++)
#define loop2(n) for(int j = 0; j < n; j++)

class ListNode {
public:
    ListNode* next;
    int val;

    ListNode(int v) {
        next = NULL;
        val = v;
    }
};

class LinkedList {
public:
    ListNode* head;

    LinkedList(){
        head = NULL;
    }

    // add a new node to the end
    void addNode(int val){
        ListNode* node = new ListNode(val); 
        if(head == NULL){
            // assign the current node to NULL
            head = node;
        }
        else{
            // move to the last and then add the node
            ListNode* temp = head;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = node;
        }
    }

    void printLinkedList(){
        ListNode* temp = head;
        while(temp != NULL){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << "" << endl;
    }

};

// Remove loop in the Linked list
void Sol(){
    LinkedList* l = new LinkedList;
    l->addNode(5);
    l->addNode(3);
    l->addNode(7);
    l->addNode(4);
    l->printLinkedList();
}

void RepSolution(){
    int t;
    cin >> t;
    while(t!=0){
        Sol();
        t--;
    }
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //RepSolution();
    Sol();
    return 0;
}
