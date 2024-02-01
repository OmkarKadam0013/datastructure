#include<iostream>
#include<vector>
using namespace std;
class probing{
    vector<int>hashtable;
    int buckets;
    public:
    probing(int size){
        buckets = size;
        hashtable.resize(buckets);
    }
    int hashval(int key){
        return key%buckets;
    }
    void addKey(int key){
        int idx = hashval(key);
        if(hashtable[idx] == 0){
        hashtable[idx] = key;
            }
        else if(hashtable[idx] != 0){
            int i;
            i = idx;
            while(!hashtable[i] == 0){
                if(i == hashtable.size()-1){
                    if(hashtable[i]==0){
                    hashtable[i] = key;}
                    else{
                        i = 0;
                    }
                }
                if(i == (idx - 1) && hashtable[i] != 0){
                    cout<<"Not empty space "<<endl;
                    break;
                }
                 i++; 
            }
            hashtable[i] = key;
        }

        else{
        cout<<"Can't add this key "<<endl;
    }
    }
    
    void display(){
         for(int i = 0 ;i<hashtable.size();i++){
        cout<<hashtable[i]<<endl;
  }
    }
    
};
int main(){
    probing h(5);
    h.addKey(10);
    h.addKey(1);
    h.addKey(19);
    h.addKey(29);
    h.addKey(3);
    h.addKey(4);

    h.display();
    // int n;
    // cout<<"Enter the size of hash table : ";
    // cin>>n;
    // probing h(n);
    // int choice;
    // while(1){
    // cout<<"Enter 1 for add key and 2 for display :";
    // cin>>choice;
    // switch (choice)
    // {
    // case 1:{
    //     int k;
    //     cout<<"Enter key :";
    //     cin>>k;
    //     h.addKey(k);

    // }
        
    //     break;
    //     case 2:{
    //         h.display();

    // }
        
    //     break;

    
    // default:
    // cout<<"Invalid choice : ";
    //     break;
    // }
    //     }

    return 0;
}