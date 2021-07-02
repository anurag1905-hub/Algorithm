#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
class Edge{
    public:
    int src,dest;
};
class Graph{
    public:
    int V,E;
    Edge* edge;
};
class subset{
    public:
    int parent;
    int rank;
};
Graph* createGraph(int V,int E){
    Graph* graph=new Graph();
    graph->V=V;
    graph->E=E;
    graph->edge=new Edge[E];
    return graph;
}
int find(subset subsets[],int i){
    if(subsets[i].parent!=i){
        subsets[i].parent=find(subsets,subsets[i].parent);
    }
    return subsets[i].parent;
}
void Union(subset subsets[],int x,int y){
    int xroot=find(subsets,x);
    int yroot=find(subsets,y);
    if(subsets[xroot].rank<subsets[yroot].rank){
        subsets[xroot].parent=yroot;
    }
    else if(subsets[xroot].rank>subsets[yroot].rank){
        subsets[yroot].parent=xroot;
    }
    else{
        subsets[yroot].parent=xroot;
        subsets[xroot].rank++;
    }
}
int kargerMincut(Graph* graph){
    int V=graph->V;
    int E=graph->E;
    Edge* edge=graph->edge;
    subset *subsets=new subset[V];
    for(int i=0;i<V;++i){
        subsets[i].parent=i;
        subsets[i].rank=0;
    }
    int vertices=V;
    while(vertices>2){
        int i=rand()%E;
        int subset1=find(subsets,graph->edge[i].src);
        int subset2=find(subsets,graph->edge[i].dest);
        if(subset1==subset2){
            continue;
        }
        else{
          cout<<"Contracting edge "<<edge[i].src<<"-"<<edge[i].dest<<endl;
          vertices--;
          Union(subsets,subset1,subset2);
        }
    }
    int cutedges=0;
    for(int i=0;i<E;++i){
        int subset1=find(subsets,graph->edge[i].src);
        int subset2=find(subsets,graph->edge[i].dest);
        if(subset1!=subset2){
            cutedges++;
        }
    }
    return cutedges;
}
int main(){
    int V=4;
    int E=5;
    Graph* graph=createGraph(V,E);
    graph->edge[0].src=0;
    graph->edge[0].dest=1;
    
    graph->edge[1].src=0;
    graph->edge[1].dest=2;
    
    graph->edge[2].src=0;
    graph->edge[2].dest=3;
    
    graph->edge[3].src=1;
    graph->edge[3].dest=3;
    
    graph->edge[4].src=2;
    graph->edge[4].dest=3;
    
    srand(time(NULL));
    cout<<"Cut found by Karger's algo is:"<<kargerMincut(graph);
}
