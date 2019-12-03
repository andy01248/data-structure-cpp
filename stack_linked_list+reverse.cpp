//Use linked link to implement Stack --> always insert/delete ata same end (begin / tail)
#include <iostream>
#include <stack>
using namespace std;

//Create own stack
// class Stack{
//     private:
//     char A[101];
//     int top;
//     public:
//     void Push(int x);
//     void Pop();
//     int Top();
//     bool IsEmpty();
// };

struct node{

    int data;
    node* next;
};
node* Head_node;

node* create_new_node(int data){
    node* new_node = new node();
    new_node->data=data;
    new_node->next=NULL;
    return new_node;
}

void push(int data){  //always push in the begining
        node* new_node = create_new_node(data);
        new_node->next=Head_node;
        Head_node=new_node;   
}
void pop(){
    if (Head_node==NULL){
        cout<<"no element in stack\n";
        return;
    }
    else{
    node* temp=Head_node;
    Head_node=Head_node->next;
    delete(temp);
    }
}

void print(){
    node* temp= Head_node;

    while( temp!=NULL){
        cout<<temp->data<<"\n";
        temp=temp->next;
    }

}

void Reverse_linked_list(){
    node* temp=Head_node;
    stack<node*> S;
    while(temp!=NULL){
        S.push(temp);
        temp=temp->next;
    }
    node* temp2=S.top();
    Head_node=temp2;
    S.pop();
    while(!S.empty()){
        temp2->next=S.top();
        S.pop();
        temp2=temp2->next;
    }
    temp2->next=NULL;

}

int main(){
    Head_node=NULL;
    push(5);
    push(6);
    push(8);
    push(1);
    push(2);
    push(3);

    print();
    Reverse_linked_list();
    print();
}