#include<iostream>
#include<string>
using namespace std;
struct node{
    int tel;
    string name;
    node*next;

}*head;
void creat_head(){
    node*newnode,*temp;
    head = NULL;
    int m;
    cout<<"Enter the size of hash table :";
    cin>>m;
    for(int i = 0; i<m;i++){
    newnode = new node;
    newnode->tel = 0;
    newnode->name = "None";
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
        temp = head;
    }
    else{
        temp->next = newnode;
        temp = newnode;
    }
    }
 
}
void display(){
  node*temp;
  temp = head;
  while(temp != NULL){
    cout<<temp->tel<<"\t";
    cout<<temp->name<<endl;
    temp = temp->next;
  }
}
void add_elements(){
  node*temp;
  temp = head;
  string name;
  int pos,m,k,n;
  cout<<"Enter the size of hash table :";
  cin>>m;
  cout<<"Enter how many numberes do you  wnat to add? :";
  cin>>n;
  for(int j = 0;j<n;j++){
    cout<<"Enter name:";
    cin>>name;
  cout<<"Enter the key : ";
  cin>>k;
  int pos = k % m;
  int i = 0;
  temp = head;
  while(i < pos ){
    temp = temp->next;
    i++;
  }
  temp->name = name;
  temp->tel = k;
  }
}
int main(){
    creat_head();
    add_elements();
  display();

  return 0;
}