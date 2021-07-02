#include<iostream>
#include<list>
#include<queue>
#include<limits.h>
#define ipair pair<int,int>
using namespace std;
class Graph{
    private:
    int V;
    list<pair<int,int>>* adj;

    public:
    Graph(int v){
        this->V=v;
        adj=new list<ipair>[V];
    }
    
    void addEdge(int src,int dest,int weight){
        adj[src].push_back(make_pair(dest,weight));
        adj[dest].push_back(make_pair(src,weight));
    }
    
    void dijkistra(int src){
        priority_queue<ipair,vector<ipair>,greater<ipair>>pq;
        vector<int>dist(V,INT_MAX);
        pq.push(make_pair(0,src));
        dist[src]=0;
        
        while(!pq.empty()){
            int u=pq.top().second;
            pq.pop();
            list<pair<int,int>>::iterator it;
            for(it=adj[u].begin();it!=adj[u].end();++it){
                int v=(*it).first;
                int weight=(*it).second;
                
                if(dist[v]>dist[u]+weight){
                    dist[v]=dist[u]+weight;
                    pq.push(make_pair(dist[v],v));
                }
            }
        }
        cout<<"Vertex     Distance from source"<<endl;
        for(int i=0;i<V;++i){
            cout<<i<<"\t"<<"\t"<<dist[i]<<endl;
        }
    }
};
int main(){
    Graph g(9);
    g.addEdge(0,1,4);
    g.addEdge(0,7,8);
    g.addEdge(1,2,8);
    g.addEdge(1,7,11);
    g.addEdge(2,3,7);
    g.addEdge(2,8,2);
    g.addEdge(2,5,4);
    g.addEdge(3,4,9);
    g.addEdge(3,5,14);
    g.addEdge(4,5,10);
    g.addEdge(5,6,2);
    g.addEdge(6,7,1);
    g.addEdge(6,8,6);
    g.addEdge(7,8,7);
    g.dijkistra(0);
}