#include<iostream>
using namespace std;
struct node{
    string key;
    string meaning;
    node*left;
    node*right;
    int height;
};
int getHeight(node*n){
    if(n == NULL){
        return 0;
    }
    return n->height;
}
int balanceFacter(node*n){
    if(n == NULL){
        return 0;
    }
    return getHeight(n->left) - getHeight(n->right);
}
node* create(string key,string meaning){
    node*newnode = new node;
    newnode->key = key;
    newnode->meaning = meaning;
    newnode->left =NULL;
    newnode->right = NULL;
    newnode->height = 1;
    return newnode;
}
node* RightRotate(node*y){
    node*x = y->left;
    node*T2 = x->right;

    x->right = y;
    y->left = T2;

    x->height = max(getHeight(x->left),getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left),getHeight(y->right)) + 1;
    return x;
}
node* LeftRotate(node*m){
    node*n = m->right;
    node*t = n->left;
    n->left = m;
    m->right = t;
    m->height = max(getHeight(m->left),getHeight(m->right)) + 1;
    n->height = max(getHeight(n->left),getHeight(n->right)) + 1;
    return n;
}
node* insert(node*n,string key,string meaning){
    if(n == NULL){
        return create(key,meaning);
    }
    if(key<n->key){
        n->left = insert(n->left,key,meaning);
    }
    else if(key > n->key){
        n->right = insert(n->right,key,meaning);
    }

    n->height = 1 + max(getHeight(n->left),getHeight(n->right));
    int bf = balanceFacter(n);
    if(bf > 1 && key < n->left->key){
        return RightRotate(n);
    }
    if(bf < -1 && key > n->right->key){
        return LeftRotate(n);
    }
    if(bf > 1 && key > n->left->key){
        n->left = LeftRotate(n->left);
        return RightRotate(n);
    }
    if(bf<-1 && key < n->right->key){
        n->right = RightRotate(n->right);
        return LeftRotate(n);
    }
    return n;

}
node*smallest(node*root){
    node*temp;
    temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}
node* deleteKey(node*root,string key){
    node*small;
    if(root == NULL){
        return NULL;
    }
    if(root->key > key){
        root->left = deleteKey(root->left,key);
    }
    else if(key > root->key){
        root->right = deleteKey(root->right,key);
    }
    else{
        if(root->right != NULL){
            small = smallest(root->right);
            root->key = small->key;
            root->meaning = small->meaning;
            root->right = deleteKey(root->right,small->key);
        }
        else{
            return root->left;
        }
    }
    root->height = 1 + max(getHeight(root->left),getHeight(root->right));
    int bf = balanceFacter(root);
    if(bf > 1 && key < root->left->key){
        return RightRotate(root);
    }
    if(bf < -1 && key > root->right->key){
        return LeftRotate(root);
    }
    if(bf > 1 && key > root->left->key){
        root->left = LeftRotate(root->left);
        return RightRotate(root);
    }
    if(bf<-1 && key < root->right->key){
        root->right = RightRotate(root->right);
        return LeftRotate(root);
    }

    return root;
}
void update(node*root,string key,string meaning){
    if(root == NULL){
        return;
    }
    else if(key < root->key){
        update(root->left,key,meaning);
    }
    else if(key > root->key){
        update(root->right,key,meaning);
    }
    else{
        root->meaning = meaning;
    }
    return;

}

void displayin(node*root){
    if(root == NULL){
        return ;
    }
    displayin(root->left);
    cout<<root->key<<" : ";
    cout<<root->meaning<<"\t";
    displayin(root->right);

}

void displaypre(node*root){
    if(root == NULL){
        return ;
    }
    cout<<root->key<<" : ";
    cout<<root->meaning<<"\t";
    displaypre(root->left);
    displaypre(root->right);

}

int main(){
    node*root = NULL;
    root = insert(root,"ant","Mungi");
    root = insert(root,"banana","Keli");
    root = insert(root,"cat","Manjar");
    root = insert(root,"dog","Kutra");
    root = insert(root,"elephant","Hatti");
    cout<<"-----------Displaying inorder---------"<<endl;
    displayin(root);
    cout<<endl;
    cout<<"-----------Displaying prorder----------"<<endl;
    displaypre(root);
    cout<<endl;
    deleteKey(root,"banana");
    cout<<"After deleting the node :"<<endl;
    update(root,"ant","Manus");
    displayin(root);
    cout<<endl;
    displaypre(root);
    return 0;
}