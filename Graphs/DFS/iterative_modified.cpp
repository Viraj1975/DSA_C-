#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int>*adj;
    public:
        Graph(int V){
            this->V = V;
            adj = new list<int>[V];
        }
        void addEdge(int v,int w);
        void DFS();
        void DFS_util(int v,vector<bool>&visited);
};

void Graph::addEdge(int v,int w){
    adj[v].push_back(w);
}

void Graph::DFS_util(int v,vector<bool>&visited){
    stack<int>s;
    s.push(v);
    while(!s.empty()){
        int x = s.top();
        s.pop();

        if(!visited[x]){
            visited[x] = true;
            cout<<x<<" ";
        }

        for(auto i=adj[x].begin();i!=adj[x].end();i++){
            if(!visited[*i]){
                s.push(*i);
            }
        }
    }
}

void Graph::DFS(){
    vector<bool>visited(V,false);

    for(int i=0;i<V;i++){
        if(!visited[i]){
            DFS_util(i,visited);
        }
    }
}

int main(){
    Graph g(5);
    g.addEdge(1, 0);
    g.addEdge(2, 1);
    g.addEdge(3, 4);
    g.addEdge(4, 0);
 
    cout << "Following is Depth First Traversal\n";
    g.DFS();
    return 0;
}