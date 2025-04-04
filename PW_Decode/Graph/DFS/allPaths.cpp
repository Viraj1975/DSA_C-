#include<bits/stdc++.h>
using namespace std;

vector<list<int>>Graph;
unordered_set<int>visited;
vector<vector<int>>paths;

void addEdge(int src,int dest,bool bi_dir=false){
    Graph[src].push_back(dest);
    if(bi_dir){
        Graph[dest].push_back(src);
    }
}

void dfs(int curr,int dest,vector<int>&temp){
    if(curr==dest){
        temp.push_back(curr);
        paths.push_back(temp);
        temp.pop_back();
        return;
    }
    visited.insert(curr);
    temp.push_back(curr);
    for(int x : Graph[curr]){
        if(not visited.count(x)){
            dfs(x,dest,temp);
        }
    }
    visited.erase(curr);
    temp.pop_back();
}

void allPaths(int src,int dest){
    vector<int>v;
    dfs(src,dest,v);
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
    cin>>src>>dest;
    allPaths(src,dest);
    return 0;
}