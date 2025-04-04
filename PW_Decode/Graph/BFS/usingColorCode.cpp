#include<bits/stdc++.h>
using namespace std;

vector<list<int>>Graph;
unordered_set<int,int>visited;
int v;

void addEdge(int src,int dest,bool bi_dir = false){
    Graph[src].push_back(dest);
    if(bi_dir){
        Graph[dest].push_back(src);
    }
}

// BFS
void ShortestPath(int src,vector<int>&dist){
    queue<int>q;
    q.push(src);
    vector<int>pred(v,-1);
    vector<char>color(v,'W');
    color[src]='g';
    dist.resize(v,INT_MAX);
    dist[src] = 0;

    while(!q.empty()){
        int x = q.front();
        cout<<x<<" ";
        q.pop();
        for(int neighbour : Graph[x]){
            if(color[neighbour]=='W'){
                color[neighbour]='g';
                q.push(neighbour);
                dist[neighbour] = dist[x]+1;
                pred[neighbour] = x;
            }
        }
        color[x]='B';
    }
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

    int src;
    cin>>src;
    vector<int>dist;
    ShortestPath(src,dist);
    // dist array will have distance of every vertex from the source vertex
    return 0;
}