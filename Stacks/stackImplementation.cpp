#include<iostream>
using namespace std;

class Stack{
    public:
    int *arr;
    int top;
    int size;

    Stack(int size){
        this->size=size;
        arr = new int[size];
        top =-1;
    }

    void push(int element){
        if(size - top>1){
            top++;
            arr[top]=element;

        }
        else{
            cout<<"Stack overflow "<<endl;
        }

    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
        cout<<"Stack underflow";
        }
    }
    int peek(){
        if(top >=0){
            return arr[top];
        }
        else{
            cout<<"Stack is empty"; 
        }
    }
    
    bool isEpmty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(){

    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    s.pop();

    cout<<s.peek();
    return 0;
}