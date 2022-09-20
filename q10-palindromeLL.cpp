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

Node* getMiddlle(Node* head){
    Node* slow = head;
    Node* fast = head -> next;
    while(fast != NULL && fast -> next != NULL){
        fast = fast -> next -> next;
        slow = slow -> next;
    }

    return slow;
}

Node* reverse(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* forw = NULL;

    while(curr != NULL){
        forw = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forw;
    }

    return prev;
}

bool isPalindrome(Node* head){

    if(head -> next == NULL){
        return true;
    }

    //getting middle node
    Node* middle = getMiddlle(head);

    Node* temp = middle -> next;
    middle -> next = reverse(temp);

    //compare the data of linked list part by part
    Node* head1 = head;
    Node* head2 = middle -> next;

    while(head2 != NULL){
        if(head1 -> data == head2 -> data){
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        else {
            return false;
        }
    }

    return true;

}

void display(Node* head){
    Node* temp = head;              //created new node with name temp

    while(temp != NULL){
        cout<<temp -> data<<" ";    //it will print the data stored at particular node
        temp = temp -> next;        //it will update the address at next so that it will point to another node in LL
    }
    cout<<endl;
}

int main(){

    Node* new_node = new Node(1);
    Node* head = new_node;
    Node* end = new_node;

    insertAtEnd(head, end, 2);
    insertAtEnd(head, end, 3);
    insertAtEnd(head, end, 2);
    insertAtEnd(head, end, 1);

    display(head);
    if(isPalindrome(head)){
        cout<<"palindrome"<<endl;
    }
    else{
        cout<<"Not a palindrome"<<endl;
    }

    return 0;
}