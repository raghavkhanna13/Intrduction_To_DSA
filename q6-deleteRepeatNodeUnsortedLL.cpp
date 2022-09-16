#include <bits/stdc++.h> 
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtEnd(Node* &head, Node* &end, int d){

    //handling the case if there is no element in Linked List
    if(head == NULL){
        Node* new_node = new Node(d);
        head = new_node;
        end = new_node;
    }
    else{
        Node* new_node = new Node(d);   //new node create
        end -> next = new_node;         //it will store the address of new_node in its next pointer type
        end = new_node;                 //it will point to the new_node created
    }
}

Node *removeDuplicates(Node *head)
{
    // Write your code here
    if(head == NULL){
        return NULL;
    }
    
    Node* curr = head;
    Node* prev = NULL;
    unordered_map<int, bool> m;
    while(curr != NULL){

        if(m[curr -> data] == true){
            prev -> next = curr -> next;
            Node* temp = curr;
            
            curr = curr -> next;
            delete temp;

        }
       else{
        m[curr -> data] = true;
        prev = curr;
        curr = curr -> next; 
       }
    }
    return head;
}

void display(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> data <<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main(){
    
    Node* head = NULL;
    Node* end = NULL;

    insertAtEnd(head, end, 1);
    insertAtEnd(head, end, 2);
    insertAtEnd(head, end, 3);
    insertAtEnd(head, end, 4);
    insertAtEnd(head, end, 2);
    insertAtEnd(head, end, 3);
    display(head);

    removeDuplicates(head);
    display(head);

    return 0;
}