#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    Node *next;
    Node *arb;

    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

//only class is created here no main function is present
// Approach 1
class Solution1
{
    private:
    void insertAtEnd(Node* &head, Node* &end, int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            end = newNode;
            return;
        }
        else{
            end -> next = newNode;
            end = newNode;
        }
        
        // return head;
    }
    public:
    Node *copyList(Node *head)
    {
        //Write your code here
        Node* temp = head;
        
        Node* cloneHead = NULL;
        Node* cloneEnd = NULL;
        
        //step1 clone given linked list using next ptrs
        while(temp != NULL){
            insertAtEnd(cloneHead, cloneEnd,  temp -> data);
            temp = temp -> next;
        }
        
        //step 2 create a map
        unordered_map<Node*, Node*> m;
        
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL){
            m[originalNode] = cloneNode;
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }
        
        //step3 clone the random pointers using arb(given name of pointer)
        
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL){
            cloneNode -> arb = m[originalNode -> arb];
            originalNode = originalNode -> next;
            cloneNode = cloneNode -> next;
        }
        
        return cloneHead;
        
    }

/*
    Time complexity = O(n)
    Space Complexity = O(n)
*/
};



//Approach 2
class Solution2
{
    private:
    void insertAtEnd(Node* &head, Node* &end, int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            end = newNode;
            return;
        }
        else{
            end -> next = newNode;
            end = newNode;
        }
        
        // return head;
    }
    public:
    Node *copyList(Node *head)
    {
        //Write your code here
        Node* cloneHead = NULL;
        Node* cloneEnd = NULL;
        
        Node* temp = head;
        
        //step1 cloning a given list with next ptr
        while(temp != NULL){
            insertAtEnd(cloneHead, cloneEnd, temp -> data);
            temp = temp -> next;
        }
        
        //step2 adding clone list nodes between original list
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL){
            Node* next = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = next;
            
            next = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode = next;
        }
        
        //step3 add random pointers to the cloned list nodes
        temp = head;
        while(temp != NULL){
            if(temp -> next!= NULL){
                if(temp -> arb != NULL){
                    temp -> next -> arb = temp -> arb -> next;
                }
                else{
                    temp -> next -> arb = temp -> arb;
                }
            }
            temp = temp -> next -> next;
        }
        
        //step4 revert the step 2
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL){
            originalNode -> next = cloneNode -> next;
            originalNode = originalNode -> next;
            
            if(originalNode != NULL){
                cloneNode -> next = originalNode -> next;
            }
            cloneNode = cloneNode -> next;
        }
        
        //step5 return the cloneHead
        return cloneHead;
        
    }
    /* Time complexity = O(n)
        Space Complexity = O(1)
    */

};

int main(){

    return 0;
}