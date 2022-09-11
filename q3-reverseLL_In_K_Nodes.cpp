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

Node* kReverse(Node* &head, int k){

    if(head == NULL){
        return head;
    }

    //iterative approach for first k nodes to reverse them
    Node * curr = head;
    Node * prev = NULL;
    Node * next = NULL;
    int count = 0;

    while(curr != NULL && count < k){
        next = curr -> next;
        curr -> next = prev;
        prev = curr; 
        curr = next;
        count++;
    }

    //add recursive part to next of head
    if(next != NULL){
        head -> next = kReverse(next, k);
    }

    return prev;

    /*
        Time complexity = O(n)
        Space complexity = O(n)
    */
}

void display(Node* temp){
    Node* ptr = temp;
    while(ptr != NULL){
        cout<<ptr -> data<<" ";
        ptr = ptr -> next;
    }
    cout<<endl;
}

int main(){

    Node* head = NULL;
    Node* end = NULL;
    cout<<"Enter how many elements you want to enter in LL: ";
    int num; cin>>num;


    insertingInList(head, end, num);

    int k;
    cout<<"Enter the value of K = ";
    cin>>k;

    Node* result = kReverse(head, k);

    display(result);

    return 0;
}