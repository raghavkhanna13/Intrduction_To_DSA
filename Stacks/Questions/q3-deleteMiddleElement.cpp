//delete middle element in stacks

#include"bits/stdc++.h"
using namespace std;

void deleteMiddle(stack<int>&st,int index, int size){
    if(index == size/2){
        cout<<st.top();
        st.pop();
        return;
    }

    int num = st.top();
    st.pop();

    deleteMiddle(st,index+1, size);
    
    st.push(num);
}

int main(){

    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    deleteMiddle(st, 0, 5);

}