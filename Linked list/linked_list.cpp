#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};
node* Create_node(int data){
    node* temp=new node();
    temp->data=data;
    temp->next=NULL;
    return temp;
}
node* Insertatend(node* head_node, int data){

    if (head_node==NULL)
    {      
        head_node=Create_node(data);
    }
    else
    {
        head_node->next=Insertatend(head_node->next,data);
    } 
    return head_node;
}

node* Insertatanywhere(node* head_node, int data,int position){
    int length=0;
    node* temp1= head_node;
    while(temp1!=NULL){
        temp1=temp1->next;
        length++;
    }
    if (position-length > 1)
    {
        cout<<"Invalid insert";
    }
    else
    {
        node* temp=Create_node(data);     
        if (position==1)
        {      
            temp->next=head_node;
            head_node=temp;    }
        else
        {
            position--;
            head_node->next=Insertatanywhere(head_node->next,data,position);
        } 
    }
        return head_node;   //due to the return node will give the connection between nodes so we can do the current node otherwise do the previous one

}

node* deletenode(node* head_node,int position){
    if (position==1){
        delete(head_node);
        head_node=head_node->next;
    }
    // else if (position==2)
    // {
    //     node* temp2 = head_node->next->next;
    //     delete(head_node->next);
    //     head_node->next=temp2;
    //     // head_node=(head_node->next);
    // }
    else
    {
        position--;
        head_node->next=deletenode(head_node->next,position);
    }
        return head_node;  //generate the link backwards

}

node* Insertatbegin(node* head_node, int data){

        node* temp=Create_node(data);   
        temp->next=head_node;
        head_node=temp;      
        return head_node;
    }
    
// The ** make the value chagne of passed into pointer
// void Print(node** head_node){  //Tranverse the linked list with temp
//     while(*head_node!=NULL){
//         cout<<*head_node<<"  ";
//         cout<<(*head_node)->data <<"\n";
//         *head_node=(*head_node)->next;
//     }
// }

//This only pass the copy of pointer into function and the change inside the function wont affect the pointer itself.
void Print(node* head_node){  //Tranverse the linked list with temp
    //node* temp=head_node;  //we dont want to modify head_node  we use temp
    // while(temp!=NULL){
    //     cout<<temp->data <<"  ";
    //     temp=temp->next;
    // }
    while(head_node!=NULL){
        cout<<(head_node)->data <<"\n";
        head_node=(head_node)->next;
    }
}

int main(){

node* head_node = NULL;  //If we use the global variable for head_node, we dont need to return to head node every time 
// head_node=Insertatbegin(head_node,20);
// head_node=Insertatend(head_node,10);
// head_node=Insertatbegin(head_node,5);
head_node=Insertatanywhere(head_node,2,1);
head_node=Insertatanywhere(head_node,3,2);
head_node=Insertatanywhere(head_node,4,1);
head_node=Insertatanywhere(head_node,5,3);
Print(head_node);

head_node=deletenode(head_node,2);

Print(head_node);

};