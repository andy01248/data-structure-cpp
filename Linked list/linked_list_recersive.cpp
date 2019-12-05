#include <iostream>
using namespace std;

struct node{

    int data;
    node* next;
};

void print(node* head_node){

    if (head_node==NULL){
        return;
    }
    cout<<head_node->data<<"\n"; //Forward print
    print(head_node->next);
   // cout<<head_node->data<<"\n"; //Backward print

}
node* Create_node(int data){
    node* temp=new node();
    temp->data=data;
    temp->next=NULL;
    return temp;
}
node* Insert(node* head_node,int data){
    node *New_Node=Create_node(data);
    if (head_node==NULL){
        head_node=New_Node;
    }
    else
    {   node* temp=head_node;
        temp->next=Insert(temp->next,data);//Recersive
        // while(temp->next!=NULL){
        //     temp=temp->next;
        // }
        // temp->next=New_Node;

    }
    return head_node;
    
}

node* Reverse(node* headnode){
    node* current=headnode;
    
    node* new_head_node=NULL;
    //node* =NULL;

    if (current->next==NULL){
        return current;
    }
    else{
        new_head_node=Reverse(current->next);
        current->next->next=current;
        current->next=NULL;
    }
    return new_head_node;

}
int main(){

    node* head_node =NULL;
    head_node=Insert(head_node,2);
    head_node=Insert(head_node,3); 
    head_node=Insert(head_node,4); 

    print(head_node);
    head_node=Reverse(head_node);
    print(head_node);
}