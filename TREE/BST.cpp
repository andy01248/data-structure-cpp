#include <iostream>
using namespace std;
#include<stack>

struct node{     //The user defined data strcutre node
    int data;       //The node value
    node* left;  //Store the left subtree root address
    node* right; //Store the right subtree root address
};
node* GetNewnode(int data){        //Create a new node with value=data and left/right = NULL
    node* Newnode = new node();
    //(*Newnode).data = data; //Same function with diffrerent expression
    Newnode->data = data;
    Newnode->left = Newnode ->right = NULL;
    return Newnode; //Return the address of new node
}

node* Insert_iteration(node *root, int data){ //iteration way to insert
    node* new_node= GetNewnode(data);
    node* temp=root;
    node* prev;
    if (temp==NULL){        
        return new_node;
    }
    //Stupid way to find the last node
    // while(!(data<=temp->data && temp->left==NULL) && !(data>temp->data && temp->right==NULL)){
    //     if (data<=temp->data){
    //         temp=temp->left;
    //     }
    //     else{
    //         temp=temp->right;
    //     }
    // }
    //     if (data<=temp->data){
    //         temp->left=new_node;
    //     }
    //     else{
    //         temp->right=new_node;
    //     }    
    //Create a previous node and use it directly 
    while(temp!=NULL){
        if (data<=temp->data){
            prev=temp;
            temp=temp->left;
        }
        else{
            prev=temp;
            temp=temp->right;
        }
    }
        if (data<=prev->data){
            prev->left=new_node;
        }
        else{
            prev->right=new_node;
        }   
        return root;
}


node* Insert(node* root, int data){      //Find the proper way to insert the node with value=data

    if (root == NULL){          //If there is no subtree(no node below)
        root = GetNewnode(data); //Create a new node with address root
    }
    else if(data <= root->data){
        root->left = Insert(root->left,data);  //if data<value go to insert the data on the left. Compare the data until there is no subtree
    }
    else
    {
        root->right = Insert(root->right,data);
    }    
    return root;

} 

bool search(node* root, int data){

    if (root == NULL) return false;
    else if (data == root->data) return true;
    else if (data <= root->data) return search(root->left,data);
    else return search(root->right,data);
}

void printnodepre(node* root){
    if (root == NULL){
        return ;
    }
    printnodepre(root->left);
        cout<<root->data<<" ";
    printnodepre(root->right);
}

void printnodein(node* root){
    if (root == NULL){
        return ;
    }
    cout<<root->data<<" ";
    printnodein(root->left);
    printnodein(root->right);
}
void printnodepost(node* root){
    if (root == NULL){
        return ;
    }
    printnodein(root->right);
    cout<<root->data<<" ";
    printnodein(root->left);
}    

int main(){
//node* rootPtr; //to store address of root node. The ptr type is node type
//rootPtr = NULL; //When tree is empty, rootPtr is NULL
node* root=NULL; // Create a empty tree. The only entry to the tree
node* root2=NULL;
root = Insert(root,15); //Every time the insertion starting form roof
// Insert1(&rootPtr,15);   //Same way
root = Insert(root,10);  //The Recersive process return back to the top
root = Insert(root,20);
root = Insert(root,6);
root = Insert(root,23);
// root = Insert(root,59);
// root = Insert(root,12);
// root = Insert(root,14);
// root = Insert(root,18);
// root = Insert(root,28);
printnodein(root);
root2 = Insert_iteration(root2,15); //Every time the insertion starting form roof
// Insert1(&rootPtr,15);   //Same way
root2 = Insert_iteration(root2,10);  //The Recersive process return back to the top
root2 = Insert_iteration(root2,20);
root2 = Insert_iteration(root2,6);
root2 = Insert_iteration(root2,23);

printnodein(root2);
//printnodepre(root);

// int number;
// cout<<"Enter the search number\n";
// cin>>number;
// if(search(root,number)) cout<<"Number is here\n";
// else cout<<"Sorry not found\n";

};

