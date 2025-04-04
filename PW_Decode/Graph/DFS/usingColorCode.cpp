#include<bits/stdc++.h>
using namespace std;

vector<list<int>>Graph;
int v,t;

void addEdge(int src,int dest,bool bi_dir = false){
    Graph[src].push_back(dest);
    if(bi_dir){
        Graph[dest].push_back(src);
    }
}

void dfs_visit(int curr,vector<int>&d,vector<int>&pred,vector<int>&color){
    color[curr]='G';
    t++;
    d[curr]=t;
    for(int neighbour : Graph[curr]){
        if(color[neighbour]=='W'){
            pred[neighbour]=curr;
            dfs_visit(neighbour,d,pred,color);
        }
    }
    color[curr]='B';
}

bool dfs(){
    vector<int>d(v,INT_MAX);
    vector<int>pred(v,-1);
    t = 0;
    vector<int>color(v,'W');
    for(int i=0;i<v;i++){
        if(color[i]=='W'){
            dfs_visit(i,d,pred,color);
        }
    }

}

int main(){
    int e;
    cin>>v>>e;
    Graph.resize(v,list<int>());
    while(e--){
        int src,dest;
        cin>>src>>dest;
        addEdge(src,dest);
    }
    dfs();
    return 0;
}

