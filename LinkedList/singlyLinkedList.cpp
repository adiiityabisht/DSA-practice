#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this-> data= data;
        this->next=NULL;
    }
    
    ~Node(){
        int value=this->data;
        if (this-> next!= NULL){
            delete next;
            this->next=NULL;
        }
    }
};

void insertAtHead(Node* &head, int d){

    Node* temp=new Node(d);
    temp->next=head;
    head = temp;

}
void insertAtTail(Node* &tail, int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}
void deleteNode(Node* Head, int position){
    Node* temp=Head;
    if(position==1){
        Head=Head->next;
        temp->next=NULL;
        delete temp;

    }
    else{
        Node* curr=Head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt<position){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}

void insertAtPosition(Node* &Head,Node* &Tail, int position, int d){

    if(position==1){
        insertAtHead(Head, d);
        return;
    } 

    Node* temp=Head;
    int cnt=1;

    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    if(temp->next==NULL){
        insertAtTail(Tail,d);
        return;
    }
    Node* nodetoinsert=new Node(d);
    nodetoinsert->next=temp->next;
    temp->next=nodetoinsert;
}

void print(Node* &head) {
    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main(){

    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);
    insertAtTail(tail,20);
    print(head);
    insertAtTail(tail,30);
    print(head);
    insertAtPosition(head, tail, 2, 99);
    print(head);
    deleteNode(head, 2);
    print(head);
    return 0;
}