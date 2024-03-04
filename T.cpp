#include<iostream>
using namespace std;
struct node{
    string name;
    node*left;
    node*right;
}*root;

node*create(){
    node*newnode = new node;
    newnode->left = NULL;
    newnode->right = NULL;
    string book;
    cout<<"Enter name (none for no node):";
    cin>>book;
    if(book == "none"){
        return 0;
    }
    newnode->name = book;
    cout<<"Enter the left child of"<<book;
    newnode->left = create();
     cout<<"Enter the right child of"<<book;
    newnode->right = create();
    return newnode;
}
int inorder(node* root) {
    if(root == NULL){
        return 0;
    }
        inorder(root->left);
        cout << root->name <<"\t";
        inorder(root->right);

}
int preorder(node*root){
    if(root == NULL){
        return 0;
    }
    cout<<root->name<<"\t";
    preorder(root->left);
    preorder(root->right);
}
int postorder(node*root){
    if(root == NULL){
        return 0;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->name<<"\t";
}


int main(){
    root = create();
    cout<<"inorder is :";
    inorder(root);
    cout<<endl;
    cout<<"preorder is :";
    postorder(root);
    cout<<endl;
    cout<<"preorder is :";
    preorder(root);
    cout<<endl;

    
    return 0;
}