//Doubly Linked List

#include "iostream"
using namespace std;

class Node {
    public:
        int data;
        Node* prev;
        Node* next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
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

//insertion at the beginning of the node
void insertAtBegin(Node* &head,Node* &end, int d){

    //handling the case if there is no element in Linked List
    if(head == NULL){
        Node* new_node = new Node(d);
        head = new_node;
        end = new_node;
    }

    else{
        Node* new_node = new Node(d);
        new_node -> next = head;
        head -> prev = new_node;
        head = new_node;
    }
}

//inserting at the end of the node
void insertAtEnd(Node* &head, Node* &end, int d){

    //handling the case if there is no element in Linked List
    if(head == NULL){
        Node* new_node = new Node(d);
        head = new_node;
        end = new_node;
    }
    else{
        Node* new_node = new Node(d);
        end -> next = new_node;
        new_node -> prev = end;
        end = new_node;
    }
}

//insert at any position of node
void insertAtPosition(Node* &head, Node* &end, int position, int d){

    
    //inserting at beginning
    if(position == 1){
        insertAtBegin(head, end, d);
        return;
    }

    Node* temp = head;
    //inserting at middle and end
    int count = 1;
    while(count < position - 1){
        temp = temp -> next;
        count++;
    }

    //inserting at end
    if(temp -> next == NULL){
        insertAtEnd(head, end, d);
        return;
    }

    Node* newNodeToInsert = new Node(d);
    newNodeToInsert -> next = temp -> next;
    temp -> next -> prev = newNodeToInsert;
    temp -> next = newNodeToInsert;
    newNodeToInsert -> prev = temp;

}

void deleteByPosition(Node* &head, Node* &end, int position){

    //for deleting the first node
    if(position == 1){
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp -> next;
        temp -> next = NULL;
        //memory free
        delete temp;
    }

    //for deleting middle and last nodes
    else{
        Node* previous = NULL;
        Node* current = head;

        int count = 1;
        while(count < position){
            previous = current;
            current = current -> next;
            count++;
        }

        if(count == position){
            previous -> next = NULL;
            end = previous;
            //memory free
            delete current;
        }

        else{
            previous -> next = current -> next;
            current -> next -> prev = previous;
            current -> prev = NULL;
            current -> next = NULL;
            //memory free
            delete current;
        }
    }

}

//traversing the linked list
void printLL(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

//getting length of linked list
int getLength(Node* &head){
    int length = 0;
    Node* temp = head;
    while(temp != NULL){
        length++;
        temp = temp -> next;
    }

    return length;

}

int main() {

    // Node* new_node = new Node(10);
    Node* head = NULL;
    Node* end = NULL;
    printLL(head);
    // cout << getLength(head) << endl;

    insertAtBegin(head,end, 23);
    printLL(head);

    insertAtEnd(head, end, 34);
    printLL(head);

    insertAtPosition(head, end, 1, 798);
    printLL(head);

    insertAtPosition(head, end, 3, 48);
    printLL(head);

    insertAtPosition(head, end, 5, 78);
    printLL(head);

    cout<<"Head = "<<head -> data<<endl;
    cout<<"End = "<<end -> data<<endl;

    deleteByPosition(head, end, 5);
    printLL(head);
    cout<<"Head = "<<head -> data<<endl;
    cout<<"End = "<<end -> data<<endl;

    return 0;
}