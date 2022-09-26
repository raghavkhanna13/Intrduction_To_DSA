#include"iostream"
#include<map>
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

//using Maps one approach
bool detectLoop(Node* head ){
    map<Node*, bool> visited;

    if(head == NULL){
        return false;
    }

    Node* temp = head;
    while(temp != NULL){

        if(visited[temp] == true){
            cout<<"Loop is present at node "<<temp -> data<<endl;
            return true;
        }

        visited[temp] = true;
        temp = temp -> next;
    }

    /*
        Time complexity = O(n)
        Space complexity = O(n)
    */
}

//using floyd cycle detection algorithm  approach two
Node* floydDetectLoop(Node* head){

    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL){
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }
        
        slow = slow -> next;

        if(fast == slow){
            return slow;
        }
    }

    return NULL;

    /*
        Time complexity = O(n)
        Space complexity = O(1)
    */
}

Node* getStartingNode(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* slow = head;
    Node* intersction = floydDetectLoop(head);
    if(intersction == NULL){
        return NULL;
    }
    while(slow != intersction){
        slow = slow -> next;
        intersction = intersction -> next;
    }

    return slow;
}

//for removing the loop in LL
Node* removeLoop(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* startOfLoop = getStartingNode(head);
    Node* ptr = startOfLoop;
    if(startOfLoop == NULL){
        return head;
    }
    while(ptr-> next != startOfLoop ){
        ptr = ptr -> next;
    }

    ptr -> next = NULL;
    return head;
}
void display(Node* &head){
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
    insertAtEnd(head, end, 12);
    // insertAtEnd(head, end, 13);
    // insertAtEnd(head, end, 17);
    // insertAtEnd(head, end, 11);
    // insertAtEnd(head, end, 10);
    end -> next = head;
    // display(head);

    if(floydDetectLoop(head)){
        cout<<"Loop is present"<<endl;
    }
    else{
        cout<<"Loop is not present"<<endl;
    }
    Node* result = getStartingNode(head);
    cout<<"Loop starts at "<<result -> data<<endl;

    Node* n = removeLoop(head);
    display(n);


    return 0;
}