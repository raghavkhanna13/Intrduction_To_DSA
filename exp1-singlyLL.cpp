//Singly Linked List

#include "iostream"
using namespace std;

//class created for creating datatype of node
class Node {
    public:
        int data;   //it will store data as int
        Node* next; //it will store the address of next node

    //constructor
    Node(int data){
        this -> data = data;    //this will pass data value in data variable 
        this -> next = NULL;    //this will make the next pointer pointing to NULL
    }

    //destructor
    ~Node(){
        int value = this -> data;

        if(this -> next != NULL){
            delete next;
            this -> next = NULL;
        }

        cout<<"memory is free for node with data "<<value<<endl;
    }
};

//function for inserting element at the beginning of the linked list
void insertAtBegin(Node* &head, int d){
    Node* new_node = new Node(d);   //new node create
    new_node -> next = head;        //it will store the address (point new_node next pointer to the head pointer of the already existing node if there)
    head = new_node;                //this will point head pointer to the new_node added
}

//function for inserting element at the end of the LL
void insertAtEnd(Node* &end, int d){
    Node* new_node = new Node(d);   //new node create
    end -> next = new_node;         //it will store the address of new_node in its next pointer type
    end = new_node;                 //it will point to the new_node created
}

//function for inserting element at any position of LL
void insertAtPosition(Node* &head, Node* &end, int position, int d){
    Node* temp = head;  //created new node pointing to fisrt node in LL

    //for inserting element at the first position
    if(position == 1){
        insertAtBegin(head, d);
        return;
    }

    int count = 1;  //we have taken this one as if we want to insert at any position atleast one node is present
    //we will update the next pointer till position - 1 so that other element is inserted between
    while(count < position - 1){
        temp = temp -> next;
        count++;
    }

    //for updating the value of end node and inserting at end
    if(temp -> next == NULL){
        insertAtEnd(end, d);
        return;
    }

    Node* new_node_to_insert = new Node(d);     //created new node to be inserted

    new_node_to_insert -> next = temp -> next;  
    temp -> next = new_node_to_insert;
}

//deleting function by position of node in LL
void deleteByPosition(Node* &head, Node* &end, int position){

    //deleting the first / starting node
    if(position == 1){
        Node* temp = head;
        head = head -> next;
        //memory free
        temp -> next = NULL;
        delete temp;
    }

    //deleting the middle or last node
    else{
        Node* prev = NULL;
        Node* curr = head;

        int count = 1;
        while(count < position){
            if(count == position - 1){
                end = curr;
            }
            prev = curr;
            curr = curr -> next;
            count++;
        }

        prev -> next = curr -> next;
        //memory free
        curr -> next = NULL;
        delete curr;
    }
}

//function created for printing the linked list(LL) from beginning till end
void printLL(Node* &head){
    Node* temp = head;              //created new node with name temp

    while(temp != NULL){
        cout<<temp -> data<<" ";    //it will print the data stored at particular node
        temp = temp -> next;        //it will update the address at next so that it will point to another node in LL
    }
    cout<<endl;
}

int main() {
    Node* new_node = new Node(10);  //created the new object of class
    /*
    cout<<new_node -> data<<endl;   //printed the data
    cout<<new_node -> next<<endl;   //printed the address of next node
    */

    
    Node* head = new_node;  //head pointed to new_node
    Node* end = new_node;   //end pointing to new_node
    // printLL(head);

    insertAtEnd(end, 23);
    // printLL(head);

    insertAtEnd(end, 13);
    // printLL(head);

    insertAtPosition(head, end, 2, 14);
    // printLL(head);

    insertAtPosition(head, end, 1, 142);
    // printLL(head);

    insertAtPosition(head, end, 6, 222);
    printLL(head);
    cout<<"Head = "<<head -> data<<endl;
    cout<<"End = "<<end -> data<<endl;


    deleteByPosition(head,end, 1);
    printLL(head);

    cout<<"Head = "<<head -> data<<endl;
    cout<<"End = "<<end -> data<<endl;

    return 0;
}