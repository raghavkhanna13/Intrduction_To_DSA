#include "iostream"
using namespace std;

class TwoStack{
    public:
        int index1;
        int index2;
        int size;
        int *arr;

    TwoStack(int size){
        this -> size = size;
        arr = new int[size];
        index1 = -1;
        index2 = size;
    }

    void push1(int data){
        if(index1 < index2 - 1 && index1 < size){
            index1++;
            arr[index1] = data;
        }
        else{
            cout<<"Stack Overflow 1"<<endl;
        }
    }

    void push2(int data){
        if(index2 - 1 > index1 && index2 != -1){
            index2--;
            arr[index2] = data;
        }
        else{
            cout<<"Stack Overflow 2"<<endl;
        }
    }

    void pop1(){
        if(index1 >= 0){
            index1--;
        }
        else{
            cout<<"Stack Underflow 1"<<endl;
        }
    }

    void pop2(){
        if(index2 <= size){
            index2++;
        }
        else{
            cout<<"Stack Underflow 2"<<endl;
        }
    }


};



int main(){

    TwoStack st(6);

    st.push1(1);
    st.push1(2);
    st.push1(3);
    
    st.push2(6);
    st.push2(5);
    st.push2(4);
    st.push2(4);
    // st.push2(4);
    // st.push2(4);
    // st.push2(4);
    // st.push2(4);

    st.push1(4);

    return 0;
}