#include<iostream>
using namespace std;
#define N 5
int stack[N];
int top = -1;
void push(int x){
    if(top == N-1){
        cout<<"Overflow!!"<<endl;
    }
    else{
        top++;
        stack[top] = x;
    }
    

}
void pop(){
    if(top == -1){
        cout<<"Underflow!!"<<endl;
    }
    else{
        int item = stack[top];
        top--;
        cout<<"Poped element is :"<<item;
    }
}
void peek(){
    if(top==-1){
        cout<<"Stack is empty!!!"<<endl;

    }
    else{
        cout<<stack[top]<<endl;
    }
}
void display(){
    for(int i = top;i>=0;i--){
        cout<<stack[i]<<endl;
    }
}
int main(){
    push(100);
    push(20);
    push(30);
    push(40);
    display();
    peek();

    return 0;
}