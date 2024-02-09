#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
class hashing{
    vector<list<int>>hashtable;
    int buckets;
    public:
   hashing(int size){
    buckets = size;
    hashtable.resize(buckets);
   }
   int hashval(int key){
    return key % buckets;
   }
   void addKey(int key){
    int idx = hashval(key);
    if(hashtable[idx].size() == 0)
    hashtable[idx].push_back(key);
    else{
        int intTobereplace = *hashtable[idx].begin();
        *hashtable[idx].begin() = key;
        hashtable[idx].push_back(intTobereplace);
    }
   }
   list<int>::iterator searchKey(int key){
    int idx = hashval(key);
    return find(hashtable[idx].begin(),hashtable[idx].end(),key);
   }
   void deleteKey(int key){
    int idx = hashval(key);
    if(hashtable[idx].end() != searchKey(key)){
    hashtable[idx].erase(searchKey(key));
    }
    else{
        cout<<"Element is not present !!"<<endl;
    }
   }
   void display(){
    for(int it = 0 ;it<hashtable.size();it++){
        for(auto i = hashtable[it].begin();i != hashtable[it].end(); i++){
            cout<<"elments are "<<*i<<endl;
        }
    }
   }
   void SearchKey(int key){
    int flag  = 0;
    int idx = hashval(key);
    for(auto it = hashtable[idx].begin();it != hashtable[idx].end();it++){
            if(*it == key){
                cout<<"Element is present!"<<*it<<endl;
                flag = 1;

                
            }
    }
    if(flag == 0){
        cout<<"Element is not present!"<<endl;
    }

   }

};
int main(){
    hashing h(10);
    h.addKey(10);
    h.addKey(3);
    h.addKey(4);
    h.addKey(11);
    h.addKey(20);
    h.addKey(30);
    //h.deleteKey(3);
    h.display();
    h.SearchKey(30);
   

    return 0;
}