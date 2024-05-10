#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
struct node{
    char data;
    node*left,*right;
}*root;
void create(){
    stack<node*>s2;
    char exp[] = "+--a*bc/def";
    for(int i = strlen(exp)-1; i>=0;i--){
        if(exp[i] != '/' && exp[i] != '*' && exp[i] != '-' && exp[i] != '+'){
            node*newnode = new node;
            newnode->data = exp[i];
            newnode->left = NULL;
            newnode->right = NULL;
            s2.push(newnode);
        }
        
        if(exp[i] == '/' || exp[i] == '*' || exp[i] == '-' || exp[i] == '+'){
            node*newnode = new node;
            newnode->data = exp[i];
            newnode->left = s2.top();
            s2.pop();
            newnode->right = s2.top();
            s2.pop();
            s2.push(newnode);
            
        }
    
    }
    root = s2.top();
    s2.pop();
}
void post_order(){
    stack<node*>s3,s4;
    node*temp = root;
    s3.push(temp);
    while(!s3.empty()){
        temp = s3.top();
        s3.pop();
        s4.push(temp);
        if(temp->left != NULL){
            s3.push(temp->left);

        }
        if(temp->right != NULL){
            s3.push(temp->right);
        }

    }
    while(!s4.empty()){
        temp = s4.top();
        s4.pop();
        cout<<temp->data<<"\t";
    }
}
int display(node*root){
    if(root == NULL){
        return 0;
    }
    display(root->left);
    cout<<root->data<<"\t";
    display(root->right);
    return 0;
}
void deletetree(node*root){
    if(root == NULL){
        return;
    }
    deletetree(root->left);
    node*temp = root;
    delete root;
    deletetree(temp->right);    
}
int main(){
    root = NULL;
    create();
    // display(root);
    cout<<endl;
    cout<<"displaying postorder: ";
    post_order();
    deletetree(root);

    return 0;
}