#include<iostream>
#include<limits.h>
#define V 9
using namespace std;
void printSolution(int distance[]){
    cout<<"Vertex"<<"\t"<<"\t"<<"Distance from vertex"<<endl;
    for(int i=0;i<V;++i){
       cout<<i<<"\t"<<"\t"<<distance[i]<<endl; 
    }
}
int mindistance(int distance[],bool sptSet[]){
    int min=INT_MAX;
    int min_index;
    for(int i=0;i<V;++i){
        if(min>=distance[i]&&sptSet[i]==false){
            min=distance[i];
            min_index=i;
        }
    }
    return min_index;
    
}
void dijkistra(int graph[V][V],int src){
    int distance[V];
    bool sptSet[V];
    for(int i=0;i<V;++i){
        distance[i]=INT_MAX;
        sptSet[i]=false;
    }
    distance[src]=0;
    for(int count=0;count<V-1;++count){
       int u=mindistance(distance,sptSet); 
       sptSet[u]=true;
       for(int v=0;v<V;++v){
           if(!sptSet[v]&&graph[u][v]&&distance[u]!=INT_MAX&&distance[v]>distance[u]+graph[u][v]){
               distance[v]=distance[u]+graph[u][v];
           }
       }
    }
    printSolution(distance);
}
int main(){
    int graph[V][V]={
                     {0,4,0,0,0,0,0,8,0},
                     {4,0,8,0,0,0,0,11,0},
                     {0,8,0,7,0,4,0,0,2},
                     {0,0,7,0,9,14,0,0,0},
                     {0,0,0,9,0,10,0,0,0},
                     {0,0,4,14,10,0,2,0,0},
                     {0,0,0,0,0,2,0,1,6},
                     {8,11,0,0,0,0,1,0,7},
                     {0,0,2,0,0,0,6,7,0}
                   };
                   dijkistra(graph,0);
}