// we can use dfs to count number of connected components
#include<bits/stdc++.h>
using namespace std;

vector<list<int>>Graph;
unordered_set<int>visited;

void addEdge(int src,int dest,bool bi_dir=false){
    Graph[src].push_back(dest);
    if(bi_dir){
        Graph[dest].push_back(src);
    }
}

void dfs(int i){
    visited.insert(i);
    for(int negihbour : Graph[i]){
        if(not visited.count(negihbour)){
            dfs(negihbour);
        }
    }
}

int connected_components(int v){
    int ct = 0;
    for(int i=0;i<v;i++){
        if(not visited.count(i)){
            dfs(i);
            ct++;
        }
    }
    return ct;
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

    cout<<connected_components(v);

    return 0;
}