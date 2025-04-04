#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int>*adj;
    public:
        Graph(int v){
            this->V = v;
            adj = new list<int>[V];
        }
        void add_Edge(int v,int w);
        void DFS(int v);
};

void Graph::add_Edge(int v,int w){
    adj[v].push_back(w);
}

void Graph::DFS(int v){
    vector<bool>Visited(V,false);

    stack<int>S;
    S.push(v);
    while(!S.empty()){
        int x = S.top();
        S.pop();

        if(!Visited[x]){
            Visited[x]=true;
            cout<<x<<" ";
        }

        for(auto i=adj[x].begin();i!=adj[x].end();i++){
            if(!Visited[*i]){
                S.push(*i);
            }
        }
    }
}

int main(){
    Graph g(5);
    g.add_Edge(1,0);
    g.add_Edge(0,2);
    g.add_Edge(2,1);
    g.add_Edge(0,3);
    g.add_Edge(1,4);
    g.DFS(0);
    return 0;
}