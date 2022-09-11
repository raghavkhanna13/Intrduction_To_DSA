#include "iostream"
using namespace std;

class Node{
    public:
        int data;
        Node* next;

    //constructor
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }  


};

//taking input from the user in list
void insertingInList(Node* &head, Node* &end, int n){
    int value;
    // cin>>value;

    Node* temp;
    
    while(n--){
        cin>>value;
        if(head == NULL){
            temp = new Node(value);
            head = temp;
            end = temp;
        }
        else{
            temp = new Node(value);
            end -> next = temp;
            // temp -> prev = end;  //for DLL
            end = temp;
        }
    }
}

Node* middleNode(Node* &head){
    if(head == NULL || head -> next == NULL){
        return head;
    }

    else{
        Node* ptr = head;
        int count = 0;
        while(ptr != NULL){
            ptr = ptr -> next;
            count++;
        }

        Node* temp = head;
        while(count/2 > 1){
            temp = temp -> next;
            count--;
        }

        return temp;
    }

    /*
        Time complexity = O(n)
        Space complexity = O(1)
    */
}

void printNode(Node* ptr){
    cout<<"Middle Node = "<<ptr -> data<<endl;
}

int main(){

    Node* head = NULL;
    Node* end = NULL;
    cout<<"Enter how many elements you want to enter in LL: ";
    int num; cin>>num;

    insertingInList(head, end, num);


    Node* middle = middleNode(head);

    printNode(middle);


    return 0;
}