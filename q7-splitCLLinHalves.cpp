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

Node* split(Node *head){

    if(head == NULL || head -> next == head){
        return head;
    }

    Node* ptr = head;
    int c = 0;
    do{
        ptr = ptr -> next;
        c++;
    }while(ptr != head);

    int mid = c/2 + 1;  //for getting middle node from where split has been done
    int count = 1;

    Node* curr = head;
    Node* forw = NULL;
    while(count < mid){
        curr = curr -> next;
        count++;
    }
    forw = curr -> next;

    curr -> next = head;    //making point middle nodes next to head

    Node* head2 = forw;
    while(forw -> next != head){
        forw = forw -> next;
    }

    forw -> next = head2;

    // return head;     //only one head can be returned of both the CLL

    return head2;
}

void display(Node* head){
    Node* temp = head;
    do{
        cout<<temp -> data <<" ";
        temp = temp -> next;
    }while(temp != head);
    cout<<endl;
}

int main(){

    Node* head = NULL;
    Node* end = NULL;

    insertAtEnd(head, end, 1);
    insertAtEnd(head, end, 2);
    insertAtEnd(head, end, 3);
    insertAtEnd(head, end, 4);
    insertAtEnd(head, end, 5);
    end -> next = head;

    Node* res = split(head);

    display(res);

    return 0;
}