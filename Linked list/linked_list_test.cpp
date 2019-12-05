#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

node* head_node;  //If we use the global variable for head_node, we dont need to return to head node every time 

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

void Insertatanywhere( int data,int position){
  
        node* temp=Create_node(data);     
        if (position==1)
        {      
            temp->next=head_node;
            head_node=temp;    
            return;
        }
        node* temp2 = head_node; //use the temp2 to serach out all linked link without changing head node
        for (int i=0; i<position-2;i++){
            temp2=temp2->next;
        }
        temp->next=temp2->next; //give the next link
        temp2->next = temp;  //connect new link
}

void deletenode(int position){
    node* temp = head_node;   //have to use temp to allocate head_node and delete memory of deteled node
    if (position==1){
        head_node=temp->next;  //this will change the head_node address. Other actions on temp wont chagne head_node address
                delete(temp);
    }
    for (int i=0;i<position-2;i++){
        temp=temp->next;   //the n-1th node
    }
    node* temp2=temp->next;//allocate the nth node address to temp2
    temp->next=temp2->next; //only do value change not the address chagne
    //The chage of temp->next wont change temp2 address.
    delete(temp2);
    
    // Alternative 
    // node* temp2 = temp->next->next;
    // delete(temp->next);
    // temp->next=temp2;
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
void Print(){  //Tranverse the linked list with temp
    //node* temp=head_node;  //we dont want to modify head_node  we use temp
    // while(temp!=NULL){
    //     cout<<temp->data <<"  ";
    //     temp=temp->next;
    // }

    node* temp=head_node;
    while(temp!=NULL){
        cout<<temp->data <<"\n";
        temp=temp->next;
    }
}


int main(){
head_node=NULL;
// head_node=Insertatbegin(head_node,20);
// head_node=Insertatend(head_node,10);
// head_node=Insertatbegin(head_node,5);
Insertatanywhere(2,1);
Insertatanywhere(3,2);
Insertatanywhere(4,1);
Insertatanywhere(5,3);
Print();

deletenode(2);

 Print();

};