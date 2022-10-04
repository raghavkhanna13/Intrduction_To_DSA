#include "iostream"
using namespace std;

class Stack{
    public:
        //properties
        int size;
        int *arr;
        int index;
    
    //behaviour
    Stack(int size){
        this -> size = size;
        arr = new int[size];
        index = -1;
    }

    //functions
    void push(int data){
        if(index <= size){
            index++;
            arr[index] = data;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    void pop(){
        if(index >= 0){
            index--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }

    int top(){
        if(index >= 0){
            return arr[index];
        }
        else{
            cout<<"Stack is empty"<<endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(index == -1){
            return true;
        }
        else{
            return false;
        }
    }
    
};

int main(){

    Stack st(10);

    st.push(23);
    st.push(21);
    st.push(2);
    st.push(13);

    st.pop();
    st.push(123);
    cout<<st.top()<<endl;

    

    return 0;
}