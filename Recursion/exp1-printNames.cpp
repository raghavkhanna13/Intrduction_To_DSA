#include "iostream"
using namespace std;

int count = 0;
void printNames(){
    if(count == 5)
    return;

    cout<<"raghav"<<endl;
    count++;
    printNames();
}

int main() {

    printNames();

     return 0;
}