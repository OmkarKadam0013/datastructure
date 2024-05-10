#include<iostream>
using namespace std;
void Maxheapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i +1;
    int right = 2*i+2;
    while(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    while(right <= n && arr[largest] < arr[right]){
        largest = right;
    }
    if(largest != i){
        swap(arr[largest],arr[i]);
        Maxheapify(arr,n,largest);
    }

}
void Minheapify(int arr[],int n,int i){
    int smallest = i;
    int left = 2*i +1;
    int right = 2*i+2;
    while(left <= n && arr[smallest] > arr[left]){
        smallest = left;
    }
    while(right <= n && arr[smallest] > arr[right]){
        smallest = right;
    }
    if(smallest != i){
        swap(arr[smallest],arr[i]);
        Maxheapify(arr,n,smallest);
    }


}
int main(){
    #define n 5
    int arr[n];
    cout<<"Enter the 5 values :";
    for(int i = 0; i< n;i++){
        cin>>arr[i];
    }
    int ch;
while(1){
    cout<<"--------MENU----------"<<endl;
    cout<<"Enter 1 for max :"<<endl;
    cout<<"ENter 2 for min :"<<endl;
    cout<<"Enter your choice :";
    cin>>ch;
    switch(ch){
    case 1:
    for(int i = 5/2-1 ; i >= 0; i--){
    Maxheapify(arr, 5, i);
}
    cout<<"Mxa value is :"<<arr[0]<<endl;
        break;

    case 2:
for(int i = 5/2-1 ; i >= 0; i--){
    Minheapify(arr, n, i);
}
    cout<<"Min value is "<<arr[0]<<endl;
    break;
    default :
    cout<<"Invalid choice :";

    }

}

    return 0;
}