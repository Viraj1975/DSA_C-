#include<bits/stdc++.h>
using namespace std;

vector<list<int>>Graph;
unordered_set<int>visited;
int v;

void addEdge(int src,int dest,bool bi_dir=false){
    Graph[src].push_back(dest);
    if(bi_dir){
        Graph[dest].push_back(src);
    }
}

bool dfs(int src,int parent){
    visited.insert(src);
    for(int neighbour : Graph[src]){
        if(visited.count(neighbour) && neighbour!=parent){
            return true;
        }
        if(not visited.count(neighbour)){
            bool res = dfs(neighbour,src);
            if(res) return true;
        }
    }
    return false;
}

bool has_cycle(){
    for(int i=0;i<v;i++){
        if(not visited.count(i)){
            bool res = dfs(i,-1);
            if(res) return true;
        }
    }
    return false;
}

int main(){
    cin>>v;
    Graph.resize(v,list<int>());
    int e;
    cin>>e;

    while(e--){
        int src,dest;
        cin>>src>>dest;
        addEdge(src,dest);
    }
    cout<<has_cycle();
    return 0;
}