#include <iostream>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
#include<iterator>
// #include<vector>
using namespace std;

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

void printnodein(node* root){
    if (root == NULL){
        return ;
    }
    printnodein(root->left);
    cout<<root->data<<" ";
    printnodein(root->right);
}
void printnodepre(node* root){
    if (root == NULL){
        return ;
    }
    cout<<root->data<<" ";
    printnodepre(root->left);
    printnodepre(root->right);
}
void printnodepost(node* root){
    if (root == NULL){
        return ;
    }
    printnodepost(root->left);
    printnodepost(root->right);
        cout<<root->data<<" ";

}    

void BFS(node* root){
    if (root==NULL) return;
    queue<node*> Q; 
    Q.push(root);
    while(!Q.empty()){
        node* current = Q.front();
        Q.pop();
        if (current==NULL) continue;
        if (current->left!=NULL) Q.push(current->left);
        if (current->right!=NULL) Q.push(current->right);
        cout<< current->data<<' ';
    }
 
}

bool CheckisBST(node* root, int value){
    if(root ==NULL) return true;
    else
    {
        if (CheckisBST(root->left,value) && (value<=root->data) && CheckisBST(root->right,value))
        {   value = root->data;
            return true;}
        else return false;
    }


}

int main(){
node* root=NULL; // Create a empty tree. The only entry to the tree
node* root2=NULL;
root = Insert(root,15); //Every time the insertion starting form roof
root = Insert(root,10);  //The Recersive process return back to the top
root = Insert(root,20);
root = Insert(root,6);
root = Insert(root,23);
root = Insert(root,59);
root = Insert(root,12);
root = Insert(root,14);
root = Insert(root,18);
root = Insert(root,28);
//printnodein(root);
BFS(root);


//vector<int> v1 = {20,30,40,25,15};
//make_heap(v1.begin(),v1.end());
//cout<<v1[0];
cout<<CheckisBST(root,INT_MIN);

};

