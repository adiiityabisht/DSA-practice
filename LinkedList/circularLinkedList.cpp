#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d){
        this-> data=d;
        this->next =NULL;
    }
    ~Node() {
        int val = this -> data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data "<< val << endl;
    }
};
void insertNode( Node* &tail, int element, int d){

    if(tail==NULL){
        Node* newNode= new Node(d);
        tail = newNode;
        newNode->next=newNode;
    }
    else{
        Node* cur=tail;

        while(cur->data!=element){
            cur=cur->next;
            
        }
        Node* temp= new Node(d);
        temp->next=cur->next;
        cur->next=temp;
        
    }
}
void print(Node* tail){

    Node* temp=tail;
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    do{
        cout<<tail->data<<" ";
        tail=tail->next;
    }while(tail->next!=temp);
    cout<<endl;
}
void deleteNode(Node* &tail, int value) {

    //empty list
    if(tail == NULL) {
        cout << " List is empty, please check again" << endl;
        return;
    }
    else{
        //non-empty

        //assuming that "value" is present in the Linked List
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        //1 Node Linked List
        if(curr == prev) {
            tail = NULL;
        }

        //>=2 Node linked list
        else if(tail == curr ) {
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;

    }

}

int main(){

    Node* tail =NULL;
    insertNode(tail, 5, 3);
    print(tail);
    insertNode(tail, 3, 2);
    print(tail);
    insertNode(tail, 2, 7);
    print(tail);
    insertNode(tail, 7, 3);
    print(tail);
    return 0;
}