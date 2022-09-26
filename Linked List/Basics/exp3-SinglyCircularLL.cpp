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

//created the function for insertion of element by value in circular LL
void insertInFrontOf(Node* &end, int value, int d){

    //if list is empty
    if(end == NULL){
        Node* new_node = new Node(d);
        end = new_node;
        new_node -> next = new_node;
    }
    else{

    //if elemnts are/is present in list then insert this way
        Node* ptr = end;

        while(ptr -> data != value){
            ptr = ptr -> next;
        }

        //value found infront of which element will be inserted (ptr representing value node)
        Node* new_node = new Node(d);
        new_node -> next = ptr -> next;
        ptr -> next = new_node;
    }
}

//deleting node from the list
void deleteByValue(Node* &end, int value){

    //if list is empty
    if(end == NULL){
        cout<<"List is already empty"<<endl;
        return;
    }

    //if elements are present in list
    else{
        Node* prev = end;
        Node* curr = prev -> next;

        while(curr -> data != value){
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = curr -> next;

        //if only one node is in list
        if(prev == curr){
            end = NULL;
        }
        //if more than one node is present
        else if(end == curr){
            end = prev;
        }

        curr -> next = NULL;
        delete curr;
    }
    

}

//traversing the circular linked list
void printCLL(Node* &end){
    Node* temp = end;

    if(end == NULL){
        cout<<"List is empty nothing to show"<<endl;
        return ;
    }

    do{
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }while(temp != end);

    cout<<endl;
}

int main(){

    Node* end = NULL;

    insertInFrontOf(end, 0, 1);
    printCLL(end);

    insertInFrontOf(end, 1, 123);
    printCLL(end);

    // insertInFrontOf(end, 1, 91);
    // printCLL(end);

    // insertInFrontOf(end, 91, 77);
    // printCLL(end);

    deleteByValue(end,1);
    printCLL(end);

    return 0;
}