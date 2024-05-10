#include<iostream>
#include<vector>
using namespace std;
struct node{
    int data;
    node*left;
    node*right;
    node(int key){
        data = key;
        left = right = NULL;
    };                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
};
node*insert(node*root,int key){
    if(root == NULL){
        return new node(key);
    }
    if(root->data<key){
        root->right = insert(root->right,key);
    }
    else{
        root->left = insert(root->left,key);
    }
    return root;
}
void Inorder(node*root){
    if(root == NULL){
        return ;
    }
    Inorder(root->left);
    cout<<root->data<<"\t";
    Inorder(root->right);
}
void Preorder(node*root){
    if(root == NULL){
        return ;
    }
    cout<<root->data<<"\t";
    Preorder(root->left);
    Preorder(root->right);
}
int main(){
    node*root = NULL;
    vector<int> key = {10, 12, 20,13};
    vector<int> freq = {34, 8, 50,100};
    int max = 0;
    int index;

    while (!key.empty()) {
        int maxFreq = freq[0];
        int maxIndex = 0;
        for (int i = 1; i < freq.size(); ++i) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                maxIndex = i;
            }
        }
        root = insert(root, key[maxIndex]);
        key.erase(key.begin() + maxIndex);
        freq.erase(freq.begin() + maxIndex);
    }
    cout<<"Printing the Inorder"<<endl;
    Inorder(root);
    cout<<"Printing the preOrder"<<endl;
    Preorder(root);
    return 0;
}