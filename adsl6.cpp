#include<iostream>
#include<vector>
#include<string>
using namespace std;
class graph{
    vector<string>city;
    vector<vector<int>>a;
    public:
    void city_input(){
        int ch =1;
        while(ch){
            string c;
            cout<<"Enter the name of city :";
            cin>>c;
            city.push_back(c);
            cout<<"continue? : ";
            cin>>ch;
        }
    }
    void weight_input(){
         a.resize(city.size(),vector<int>(city.size()));
        int distance;
        for(int i = 0;i<city.size();i++){
            for(int j = 0;j<city.size();j++){
                cout<<"enter distance between "<<city[i]<<" and "<<city[j]<<" : ";
                cin>>a[i][j];
            }
        }
    }
    int is_connected(){
        for(int i = 0;i<city.size();i++){
            int count = 0;
            for(int j = 0;j<city.size();j++){
                if(a[i][j] == 0){
                    count++;
                }
            }
        if(count == city.size()){
            return 0;
        }
    }
    return 1;
    }
    void display(){
         for(int i = 0;i<city.size();i++){
            for(int j = 0;j<city.size();j++){
                cout<<a[i][j]<<"\t";
            }
            cout<<endl;
        }

    }

};
int main(){
    graph G;
    G.city_input();
    G.weight_input();
    if(G.is_connected()){
        cout<<"graph is connected !!"<<endl;;
    }
    else{
        cout<<"Graph is not connected !!!"<<endl;
    }
    G.display();
    return 0;
}