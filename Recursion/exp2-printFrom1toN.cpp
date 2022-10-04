#include "iostream"
using namespace std;

int count = 1;
void printNumber(int n){
    if(count > n)
    return;

    cout<<count<<" ";
    count++;
    printNumber(n);
}

void printReverse(int n){
    if(n < 1){
        return ;
    }
    cout<<n<<" ";
    n--;
    printReverse(n);
}

//backtracking
void printReverseB(int i,int n){
    if(i > n)
    return ;

    count++;
    printReverseB(i+1,n);
    // count++;
    cout<<i<<" ";
}

int main(){

    int n;
    cin>>n;

    printReverseB(1,n);

    return 0;
}