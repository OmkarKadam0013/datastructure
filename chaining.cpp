#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
class hashing{
    
    vector<list<int>> hashtable;
    int buckets;
    public:
    hashing(int size){
        buckets = size;
        hashtable.resize(buckets);
    }
    int hashval(int key){
        return key%buckets;
    }
    void add(int key){
        int idx = hashval(key);
        hashtable[idx].push_back(key);
    }
   list<int>::iterator searchKey(int key){
        int idx = hashval(key);
        return find(hashtable[idx].begin(), hashtable[idx].end(), key);
    }
    void deletekey(int key){
        list<int>::iterator it = searchKey(key);
        int idx = hashval(key);
        if(it != hashtable[idx].end()){
           hashtable[idx].erase(it);
        }
        else{
            cout<<"Key is no present in hash-table"<<endl;
        }
    }
};
int main(){
    hashing h(10);
    h.add(10);
    h.add(20);
    h.add(3);
    h.deletekey(3);
    h.deletekey(3);
    cout<<endl;
    cout<<"10 is at index : "<<*h.searchKey(10);
    cout<<endl;
    return 0;
}