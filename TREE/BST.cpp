#include <iostream>
using namespace std;

struct BstNode{     //The user defined data strcutre BstNode
    int data;       //The node value
    BstNode* left;  //Store the left subtree root address
    BstNode* right; //Store the right subtree root address
};
BstNode* GetNewNode(int data){        //Create a new node with value=data and left/right = NULL
    BstNode* NewNode = new BstNode();
    //(*NewNode).data = data; //Same function with diffrerent expression
    NewNode->data = data;
    NewNode->left = NewNode ->right = NULL;
    return NewNode; //Return the address of new node
}
BstNode* Insert(BstNode* root, int data){      //Find the proper way to insert the node with value=data

    if (root == NULL){          //If there is no subtree(no node below)
        root = GetNewNode(data); //Create a new node with address root
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

// void Insert1(BstNode** rootP, int data){
//     if (*rootP == NULL){
//         *rootP=GetNewNode(data);
//     }
// }

bool search(BstNode* root, int data){

    if (root == NULL) return false;
    else if (data == root->data) return true;
    else if (data <= root->data) return search(root->left,data);
    else return search(root->right,data);
}

void printnodepre(BstNode* root){
    if (root == NULL){
        return ;
    }
    cout<<root->data<<" ";
    printnodepre(root->left);
    printnodepre(root->right);
}

void printnodein(BstNode* root){
    if (root == NULL){
        return ;
    }
    printnodein(root->left);
        cout<<root->data<<" ";

    printnodein(root->right);
}
    

int main(){
//BstNode* rootPtr; //to store address of root node. The ptr type is BstNode type
//rootPtr = NULL; //When tree is empty, rootPtr is NULL
BstNode* root=NULL; // Create a empty tree. The only entry to the tree
root = Insert(root,15); //Every time the insertion starting form roof
// Insert1(&rootPtr,15);   //Same way
root = Insert(root,10);  //The Recersive process return back to the top
root = Insert(root,20);
root = Insert(root,6);
root = Insert(root,23);
root = Insert(root,59);
root = Insert(root,12);
root = Insert(root,14);
root = Insert(root,18);
root = Insert(root,28);


printnodein(root);
printnodepre(root);

int number;
cout<<"Enter the search number\n";
cin>>number;
if(search(root,number)) cout<<"Number is here\n";
else cout<<"Sorry not found\n";

};

