#include "iostream"
using namespace std;

//parameterized recursion
void summ(int i, int sum){
    if(i < 1){
        cout<<sum;
        return ;
    }

    summ(i-1, sum+i);
}

//functional recursion
int sum(int n){
    if (n == 0){
        return 0;
    }

    return n + sum(n - 1);
}

int main(){

    cout<<sum(3);

    return 0;
}