#include<iostream>
using namespace std;
class Node{
    public:
    Node* next;
    Node* prev;
    int data;

    Node(int d){
        this->data =d;
        this->next=NULL;
        this->prev=NULL;
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

void print(Node* Head){
    Node* temp=Head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int getLength(Node* Head){

    Node* temp=Head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    return count;
}

void insertAtHead(Node* &Head, int d){
    Node* temp= new Node(d);

    Head->prev=temp;
    temp->next=Head;
    Head=temp;
}

void insertAtTail(Node* &Tail, int d){
    Node* temp= new Node(d);
    Tail->next=temp;
    temp->prev=Tail;
    Tail=temp;
}
void deleteNode(Node* &Head, int position){

    
    if(position==1){
        Node* temp=Head;
        Head=Head->next;
        temp->next=NULL;
        temp->prev=NULL;
        Head->prev=NULL;
        delete temp;

    }
    else{  
        Node* back=NULL;
        Node* front=Head;
        int cnt=1;
        while(cnt<position){
            back=front;
            front=front->next;
            cnt++;
        }
        back->next=front->next;
        front->next->prev=back;
        front -> next = NULL;
        front -> prev = NULL;
        delete front;

    }

}

int main(){
    Node* node1= new Node(10);
    Node* Head=node1;
    Node* Tail=node1;
    insertAtHead(Head,20);
    print(Head);
    insertAtHead(Head,30);
    print(Head);
    insertAtHead(Head,40);
    print(Head);
    insertAtTail(Tail, 99);
    print(Head);
    deleteNode(Head,2);
    print(Head);
    return 0;
}