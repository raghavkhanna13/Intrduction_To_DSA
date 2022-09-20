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

Node* add(Node* head1, Node* head2){
    //step1 - reverse the linked lists
    head1 = reverse(head1);
    head2 = reverse(head2);



    //step2 - addition of nodes
    int carry = 0;

    Node* ansHead = NULL;
    Node* ansTail = NULL;

    while(head1 != NULL || head2 != NULL || carry != 0){

        int val1 = 0;
        if(head1 != NULL){
            val1 = head1 -> data;
        }

        int val2 = 0;
        if(head2 != NULL){
            val2 = head2 -> data;
        }

        int sum = (val1 + val2 + carry);
        int digit = sum%10;
        //step3 - create new node for digit
        insertAtEnd(ansHead, ansTail, digit);

        carry = sum/10;

        //update the pointers
        if(head1 != NULL){
            head1 = head1 -> next;
        }
        if(head2 != NULL){
            head2 = head2 -> next;
        }
    }

    //step4 - reversing the list to get the desired answer
    ansHead = reverse(ansHead);

    return ansHead;

    /*
        Time Complexity = O(n+m)
        Space Complexity = O(Max(n,m))
    */


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

    Node* l1 = new Node(5);
    Node* head1 = l1;
    Node* end1 = l1;
    insertAtEnd(head1, end1, 7);
    insertAtEnd(head1, end1, 9);

    Node* l2 = new Node(2);
    Node* head2 = l2;
    Node* end2 = l2;
    insertAtEnd(head2, end2, 8);
    // insertAtEnd(head2, end2, 9);

    display(head1);
    display(head2);

    Node* res = add(l1, l2);
    display(res);
    
    return 0;
}