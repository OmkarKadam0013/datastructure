#include<iostream>
#include<limits> 
using namespace std;
const int V = 3;
int minKey(int key[],bool mstSet[]){
    int min = numeric_limits<int>::max();
    int min_index;
    for(int v= 0;v<V;v++){
        if(mstSet[v] == false && key[v]<min){
            min = key[v],min_index = v;
        }
    }
    return min_index;
}
int printMST(int parent[],int n,int graph[V][V]){
    int cost = 0;
    for(int i = 1;i<V;i++)
    {
    cout<<parent[i]<<" to "<<i<<" is "<<graph[i][parent[i]]<<endl;
    cost = cost + graph[i][parent[i]];
    }
    cout<<"The minimum weight is :"<<cost<<endl;
}
void primMST(int graph[V][V]){
    int parent[V];
    int key[V];
    bool mstSet[V];
    for(int i = 0;i<V;i++){
        key[i] = numeric_limits<int>::max();
        mstSet[i] = false;
    }
    key[0] = 0;
    parent[0] = -1;
    for(int count = 0;count<V-1;count++){
        int u = minKey(key,mstSet);
        mstSet[u] = true;
        for(int v = 0; v<V;v++){
            if(graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]){
                  parent[v] = u,key[v] = graph[u][v];
            }
        }
    }
    printMST(parent,V,graph);
}
int main(){
    int a;
 int graph[V][V] = {{0,3,5},
        {3,0,1},
        {5,1,0}
                };
    // int ch;
    // int office[] = {0,1,2,3,4};
    // for(int i = 0; i < V ;i++){
    //     for(int j = 0;j<V;j++){
    //     cout<<"enter 1 if edge between "<<office[i]<<" and "<<office[j]<<" else 0 :";
    //     cin>>ch;
    //     if(ch){
    //     cout<<"ENter the cost of telephone lane between "<<office[i]<<" and "<<office[j]<<" : ";
    //     cin>>a;
    //     graph[i][j] = graph[j][i] = a;
    //     }
    //     else{
    //         continue;
    //     }
    //     }
    // }
    primMST(graph);
    return 0;
}