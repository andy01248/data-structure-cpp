#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};
node* Head_node;

node* Create_node(int data){
    node* temp=new node();
    temp->data=data;
    temp->next=NULL;
    return temp;
}

void Insertatanywhere( int data,int position){
  
        node* temp=Create_node(data);     
        if (position==1)
        {      
            temp->next=Head_node;
            Head_node=temp;    
            return;
        }
        node* temp2 = Head_node; //use the temp2 to serach out all linked link without changing head node
        for (int i=0; i<position-2;i++){
            temp2=temp2->next;
        }
        temp->next=temp2->next; //give the next link
        temp2->next = temp;  //connect new link
}

void deletenode(int position){
    node* temp = Head_node;   //have to use temp to allocate Head_node and delete memory of deteled node
    if (position==1){
        Head_node=temp->next;  //this will change the Head_node address. Other actions on temp wont chagne Head_node address
                delete(temp);
    }
    for (int i=0;i<position-2;i++){
        temp=temp->next;   //the n-1th node
    }
    node* temp2=temp->next;//allocate the nth node address to temp2
    temp->next=temp2->next; //only do value change not the address chagne
    //The chage of temp->next wont change temp2 address.
    delete(temp2);
}
void Reverse(){
    node* current=Head_node;
    node* prev=NULL;
    node* next;
    while(current!=NULL){
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    Head_node=prev; // Remember to change the head node
}

void Print(){  //Tranverse the linked list with temp
    node* temp=Head_node;
    while(temp!=NULL){
        cout<<temp->data <<"\n";
        temp=temp->next;
    }
}

int main(){
    Head_node=NULL;

    Insertatanywhere(3,1);
    Insertatanywhere(2,2);
    Insertatanywhere(1,3);
    Print();
    Reverse();
    Print();

}