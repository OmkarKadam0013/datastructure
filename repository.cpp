#include<iostream>
#include<iomanip>
#include<map>
#include<vector>
using namespace std;
class directory{
    vector<map<string,long>> repo;
    int buckets;
    public:
    directory(int size){
        buckets = size;
        repo.resize(buckets);
    }
    int hashval( long key){
        return key%buckets;
    }
    void addKey( long key){
       int idx = hashval(key);
       string name;
       cout<<"Enter name :";
       cin>>name;
       repo[idx].insert(pair<string, long>(name, key));
    }
    void display(){
        cout<<"--------------REPOSITORY-------------------"<<endl;
        for(int i = 0 ;i < repo.size();i++){
            for(auto ele:repo[i]){
                cout<<"The name is :"<<ele.first<<"\t";
                cout<<showpos<<"Phone no is :"<<ele.second<<endl;
            }
        }
    }


};
int main(){
    int size;
    int choice;
     cout<<"Enter the size of directory : ";
        cin>>size;
        directory d(size);
    while(1){
        cout<<"----------------MENU-----------------"<<endl;
        cout<<"Enter 1 for add entry :"<<endl;
        cout<<"Enter 2 for display repository "<<endl;
        cout<<"Enter your choice :";
        cin>>choice;
        switch (choice)
        {
        case 1:
            long mob;
            cout<<"Enter mob. number :";
            cin>>mob;
           d.addKey(mob);
            break;
        case 2 :
            d.display();
            break;
        
        default:
        cout<<"Invalid choice please re-enter the choice !";
            break;
        }
    }

    return 0;
} 

