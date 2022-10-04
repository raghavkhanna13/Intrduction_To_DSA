#include "iostream"
using namespace std;

//reverse array using recusrion
void reverse(int arr[], int i, int n){
    if(i >= n/2)
        return;
    
    swap(arr[i], arr[n - i - 1]);
    reverse(arr, i+1,n);
}

int main() {
    int n;
    cin>>n;

    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    reverse(arr,0,n);

    for(int i = 0; i < 5; i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}