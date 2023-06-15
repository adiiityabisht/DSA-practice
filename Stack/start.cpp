#include<iostream>
#include<stack>
using namespace std;

int main(){

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    s.pop();
    s.pop();

    //cout<<"top element "<< s.top();
    if(s.empty()){
        cout<<"stack is empty"<<endl;
    }
    

    s.push(1);

    cout<<"after update the size of stack is: "<< s.size();

    return 0;
}