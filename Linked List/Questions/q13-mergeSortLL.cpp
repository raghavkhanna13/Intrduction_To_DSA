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

Node* getMid(Node* head){

    Node* slow = head;
    Node* fast = head -> next;

    while(fast != NULL && fast -> next != NULL){
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    return slow;
}

Node* merge(Node* left , Node* right){

    if(left == NULL){
        return right;
    }

    if(right == NULL){
        return left;
    }

    Node* ans = new Node(-1);
    Node* temp = ans;

    while(left != NULL && right != NULL){
        if(left -> data < right -> data){
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else{
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }

    while(left != NULL){
        temp -> next = left;
        temp = left;
        left = left -> next;
    }

    while(right != NULL){
        temp -> next = right;
        temp = right;
        right = right -> next;
    }

    ans = ans -> next;
    return ans;

    

}

Node* mergeSort(Node* head){
    if(head == NULL || head -> next == NULL){
        return head;
    }

    Node* mid = getMid(head);
    Node* left = head;
    Node* right = mid -> next;
    mid -> next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    //merge the linked lists
    Node * result = merge(left, right);
    return result;

    /*
        Time Comolexity = O(nlogn)
        Space Complexity = O(n)
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

int main() {

    Node* head = NULL;
    Node* end = NULL;

    insertAtEnd(head, end, 5);
    insertAtEnd(head, end, 1);
    insertAtEnd(head, end, 3);
    insertAtEnd(head, end, 2);
    insertAtEnd(head, end, 12);
    insertAtEnd(head, end, 9);

    display(head);

    Node* res = mergeSort(head);

    display(res);


    return 0;
}