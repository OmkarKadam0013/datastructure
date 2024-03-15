#include<iostream>
using namespace std;
struct node{
    int data;
    node*left,*right;
    node(int key){
        data = key;
        left = NULL;
        right = NULL;
    }

};
node*create(node*root,int key){
    if(root == NULL){
        return new node(key);
    }
    else if(root->data > key){
        root->left = create(root->left,key);
    }
    else{
        root->right = create(root->right,key);
    }
    return root;
}
int displayinorder(node*root){
    if(root == NULL){
        return 0;
    }
    displayinorder(root->left);
    cout<<root->data<<"\t";
    displayinorder(root->right);
    return 0;
}
int search(node*root,int key){
    if(root == NULL){
        cout<<"Element is not present"<<endl;
        return 0;
    }
    if(root->data == key){
        cout<<"Element is present"<<endl;
        return 1;
    }
    else if(root->data > key){
        search(root->left,key);
    }
     else if(root->data <= key){
        search(root->right,key);
    }
    
    return 0 ;

}
int minValue(node*root){
    if(root == NULL){
        cout<<"Tree is empty "<<endl;
        return 0;
    }
    while(root->left != NULL){
        root = root->left;
    }
    cout<<"minimum value is : "<<root->data<<endl;
    return 1;
}
int change(node*root){
    if(root == NULL){
        return 0;
    }
    node*temp = root->left;
    root->left = root->right;
    root->right = temp;
    change(root->left);
    change(root->right);
    return 0;

}
int height(node*root){
    if(root == NULL){
        return -1;
    }
    else{
        int left = height(root->left);
        int right = height(root->right);
        return max(left,right)+1;
    }
}
int main(){
    node*root = NULL;
    root = create(root,10);
    create(root,108);
    create(root,2);
    create(root,4);
    create(root,104);
    create(root,65);
    displayinorder(root);
    cout<<endl;
    search(root,104);
    search(root,103);
    minValue(root);
    // change(root);
    // displayinorder(root);
    cout<<"Height is :"<<height(root)<<endl;


    return 0;
}