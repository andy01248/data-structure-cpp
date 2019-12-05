#include <iostream>
using namespace std;

struct node{
    int data;
    node* left;
    node* right;
};
node* root = NULL;

node* create_new_node(int data){
    node* new_node = new node();
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    return new_node;
}
void Insert(node** rootnode, int data){
    node* new_node=create_new_node(data);
    if (*rootnode==NULL){  //when empty tree
        *rootnode=new_node;
    }
    else
    {
        if (data<= (*rootnode)->data){
            Insert(&(*rootnode)->left,data);
        }
        else
        {   
            Insert(&(*rootnode)->right,data);
        }       
    }   
}

void print(node* rootnode){
    node* temp = rootnode;
    if (temp==NULL){
        return;
    }
    else{
        cout<<temp->data<<'\n';
        print(temp->left);
        print(temp->right);        
    }
}

int main(){

Insert(&root,15);
Insert(&root,20);
Insert(&root,10);
print(root);

}