#include <iostream>
using namespace std;

struct node{

    int data;
    node* next;
    node* prev;
};
node* Create_node(int data){
    node* temp=new node();  //if we dont use new, the node created will be removed in stack memory. So we use dynamic memory to store it
    //node* temp;
    temp->data=data;
    temp->next=NULL;
    temp->prev=NULL;
    return temp;
}

node* Head_node =NULL;

void Insertatbegin(int data){
    node* new_node = Create_node(data); 
    if (Head_node==NULL) Head_node=new_node;
    else{
    Head_node->prev=new_node;
    new_node->next=Head_node;
    Head_node=new_node;
    }


}

void Insertatend(int data){
    node* new_node = Create_node(data); 
    node* temp=Head_node;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new_node;
    new_node->prev=temp;
}
void print(){
    node* temp=Head_node;
    while(temp!=NULL){
    cout<<temp->data<<'\n';
    temp=temp->next;
    }
}
void printReverse(){
    node* temp=Head_node;
    while(temp->next!=NULL){
    temp=temp->next;
    }
    while(temp->prev!=NULL){
        cout<<temp->data<<'\n';
        temp=temp->prev;
    }
    cout<<temp->data;

}


int main(){
Insertatbegin(1);
Insertatbegin(2);
Insertatend(3);
print();
printReverse();

}