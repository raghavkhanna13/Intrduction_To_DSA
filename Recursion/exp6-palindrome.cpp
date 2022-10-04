#include "iostream"
using namespace std;

bool palindrome(string &str, int i){
    if(i >= str.size()/2)
        return true;
    
    if(str[i] != str[str.size() - i - 1])
        return false;
    
    return palindrome(str, i+1);
}

int main() {

    string str;
    cin>>str;

    if(palindrome(str, 0)){
        cout<<"Yes it is palindrome"<<endl;
    }
    else{
        cout<<"It is not a palindrome"<<endl;
    }

    return 0;
}