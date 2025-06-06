#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    bool** tc;
    list<int>*adj;
    void DFSutil(int v,int u);
    public:
        Graph(int V){
            this->V = V;
            adj = new list<int>[V];
            tc = new bool*[V];

            for(int i=0;i<V;i++){
                tc[i] = new bool[V];
                memset(tc[i],false,V*sizeof(bool));
            }
        }
        void addEdge(int u,int v);
        void Transitive_Closure();
};

void Graph::addEdge(int u,int v){
    adj[u].push_back(v);
}

void Graph::DFSutil(int u,int v){
    tc[u][v] = true;

    for(int x : adj[v]){
        if(!tc[u][x]){
            DFSutil(u,x);
        }
    }
}

void Graph::Transitive_Closure(){
    for(int i=0;i<V;i++){
        DFSutil(i,i);
    }

    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<<tc[i][j]<<" ";
        }
        cout<<endl;
    }
}



int main(){
    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(2,0);
    g.addEdge(2,3);
    g.addEdge(3,3);
    g.Transitive_Closure();
    return 0;
}