#include "iostream"
using namespace std;

class Queue{
    public:
        int qsize;
        int* arr;
        int start;
        int rear;

        Queue(int size){
            this -> qsize = size;
            arr = new int(qsize);
            start = 0;
            rear = 0;
        }

        //functions
        void push(int data){
            if(rear == qsize){
                cout<<"Queue is full"<<endl;
            }
            else{
                arr[rear] = data;
                rear++;
            }
        }

        int pop(){
            int ans = arr[start];
            if(start == rear){
                cout<<"Queue is empty"<<endl;
                start = 0;
                rear = 0;
            }
            else{
                arr[start] = -1;
                start++;
            }

            return ans;
        }

        bool isEmpty(){
            if(start == rear){
                return true;
            }
            else{
                return false;
            }
        }

        int front(){
            if(start == rear){
                cout<<"Queue is empty"<<endl;
            }
            else{
                cout<<arr[start]<<endl;
            }
        }

        int back(){
            if(rear == start){
                cout<<"Queue is empty"<<endl;
            }
            else{
                cout<<arr[rear]<<endl;
            }
        }

        int size(){
            return rear;
        }

};

int main(){

    Queue q(10);
    q.push(23);
    cout<<q.pop();
    

    return 0;
}