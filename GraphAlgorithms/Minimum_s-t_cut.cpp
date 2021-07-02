#include<iostream>
#include<string.h>
#include<limits.h>
#include<queue>
#define V 6
using namespace std;
int bfs(int rGraph[V][V],int s,int t,int parent[]){
    bool visited[V];
    memset(visited,0,sizeof(visited));
    queue<int>q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v=0;v<V;++v){
            if(visited[v]==false&&rGraph[u][v]>0){
                q.push(v);
                visited[v]=true;
                parent[v]=u;
            }
        }
    }
    return (visited[t]==true);
}
void dfs(int rGraph[V][V],int s,bool visited[]){
    visited[s]=true;
    for(int i=0;i<V;++i){
        if(rGraph[s][i]&&!visited[i]){
            dfs(rGraph,i,visited);
        }
    }
}
void minCut(int graph[V][V],int s,int t){
    int u,v;
    int rGraph[V][V];
    for(u=0;u<V;++u){
        for(v=0;v<V;++v){
            rGraph[u][v]=graph[u][v];
        }
    }
    int parent[V];
    while(bfs(rGraph,s,t,parent)){
        int path_flow=INT_MAX;
        for(v=t;v!=s;v=parent[v]){
            u=parent[v];
            path_flow=min(path_flow,rGraph[u][v]);
        }
        for(v=t;v!=s;v=parent[v]){
            u=parent[v];
            rGraph[u][v]-=path_flow;
            rGraph[v][u]+=path_flow;
        }
    }
    bool visited[V];
    memset(visited,false,sizeof(visited));
    dfs(rGraph,s,visited);
    for(int i=0;i<V;++i){
        for(int j=0;j<V;++j){
            if(visited[i]&&!visited[j]&&graph[i][j]){
                cout<<i<<"-"<<j<<endl;
            }
        }
    }
    return;
}
int main(){
    int graph[V][V]={
                      {0,16,13,0,0,0},
                      {0,0,10,12,0,0},
                      {0,4,0,0,14,0},
                      {0,0,9,0,0,20},
                      {0,0,0,7,0,4},
                      {0,0,0,0,0,0}
                    };
                    minCut(graph,0,5);
}
