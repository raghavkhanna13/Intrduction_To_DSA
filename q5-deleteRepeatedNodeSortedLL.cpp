#include "iostream"
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

Node* uniqueSortedList(Node* head){

    //empty list
    if(head == NULL){
        return NULL;
    }

    //not empty list
    Node* curr = head;
    while(curr != NULL){
        if((curr -> next != NULL) && curr -> data == curr -> next -> data){
            Node* nextToNext = curr -> next -> next;
            Node* toBeDeleted = curr -> next;

            curr -> next = nextToNext;
            delete toBeDeleted;
        }
        else{
            curr = curr -> next;
        }
    }
    return head;

    /*
        Time complexity = O(n)
        Space Complexity = O(1)
    */
}

void display(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> data <<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main() {

    Node* head = NULL;
    Node* end = NULL;

    insertAtEnd(head, end, 2);
    insertAtEnd(head, end, 2);
    insertAtEnd(head, end, 2);
    insertAtEnd(head, end, 2);
    display(head);

    uniqueSortedList(head);
    display(head);

    return 0;
}