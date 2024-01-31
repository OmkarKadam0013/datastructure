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
            int i = idx;
            while(i != 0){
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
    probing h(10);
    h.addKey(10);
    h.addKey(3);
    h.addKey(13);
    h.addKey(11);
    h.addKey(8);
    h.display();

    return 0;
}