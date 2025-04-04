#include<bits/stdc++.h>
using namespace std;

vector<list<int>>Graph;
unordered_set<int>visited;

void addEdge(int src,int dest,bool bi_dir = false){
    Graph[src].push_back(dest);
    if(bi_dir){
        Graph[dest].push_back(src);
    }
}

bool dfs(int curr,int dest){
    if(curr==dest) return true;
    visited.insert(curr);
    for(int neighbour : Graph[curr]){
        if(not visited.count(neighbour)){
            bool res = dfs(neighbour,dest);
            if(res) return true;
        }
    }
    return false;
}

bool anyPath(int src,int dest){
    return dfs(src,dest);
}

int main(){
    int v,e;
    cin>>v>>e;
    Graph.resize(v,list<int>());
    while(e--){
        int src,dest;
        cin>>src>>dest;
        addEdge(src,dest);
    }
    int src,dest;
    cout<<anyPath(src,dest);
    return 0;
}