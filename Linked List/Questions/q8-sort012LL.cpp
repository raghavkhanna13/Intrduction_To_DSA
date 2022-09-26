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


//method 1 for sorting the ll by changing data in nodes
Node* sortMeth1(Node* head){

    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;

    while(temp != NULL){
        if(temp -> data == 0){
            zeroCount++;
        }
        else if(temp -> data == 1){
            oneCount++;
        }
        else if(temp -> data == 2){
            twoCount++;
        }
        temp = temp -> next;
    }

    temp = head;

    while(temp != NULL){
        if(zeroCount != 0){
            temp -> data = 0;
            zeroCount--;
        }
        else if(oneCount != 0){
            temp -> data = 1;
            oneCount--;
        }
        else if(twoCount != 0){
            temp -> data = 2;
            twoCount--;
        }
        temp = temp -> next;
    }

    return temp;
}

//method 2 of sorting ll by not changing data of nodes directly
Node* sortMeth2(Node* head){

    Node* zeroHead = new Node(-1);
    Node* zerotail = zeroHead;
    Node* oneHead = new Node(-1);
    Node* onetail = oneHead;
    Node* twoHead = new Node(-1);
    Node* twotail = twoHead;

    Node* temp = head;

    //creating seperate nodes
    while(temp != NULL){
        if(temp -> data == 0){
            insertAtEnd(zeroHead, zerotail, 0);
            // zerotail = zerotail -> next;
        }

        else if(temp -> data == 1){
            insertAtEnd(oneHead, onetail, 1);
            // onetail = onetail -> next;
        }

        else if(temp -> data == 2){
            insertAtEnd(twoHead, twotail, 2);
            // twotail = twotail -> next;
        }

        temp = temp-> next;
    }

    //merging each node
    if(oneHead -> next != NULL){
        zerotail -> next = oneHead -> next;
    }
    else{
        zerotail -> next = twoHead -> next;
    }

    onetail -> next = twoHead -> next;
    twotail -> next = NULL;

    head = zeroHead -> next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}


void display(Node* head){
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

    insertAtEnd(head, end, 2);
    insertAtEnd(head, end, 1);
    insertAtEnd(head, end, 2);
    insertAtEnd(head, end, 0);
    insertAtEnd(head, end, 1);
    insertAtEnd(head, end, 0);
    display(head);

    Node* res = sortMeth2(head);

    display(res);


    return 0;
}

/*
For both methods
    Time complexity = O(n)
    Space complexity = O(1)
*/