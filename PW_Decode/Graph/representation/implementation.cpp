#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<list<int>>&Graph,int src,int dest,bool bi_dir = false){
    Graph[src].push_back(dest);
    if(bi_dir){
        Graph[dest].push_back(src);
    }
}

void display(vector<list<int>>&Graph){
    int n = Graph.size();
    for(int i=0;i<n;i++){
        cout<<i<<" -> ";
        for(int neighbour : Graph[i]){
            cout<<neighbour<<" ";
        }
    }
}

int main(){
    int v,e;
    cin>>v>>e;
    vector<list<int>>Graph(v,list<int>());

    while(e--){
        int src,dest;
        cin>>src>>dest;
        addEdge(Graph,src,dest);
    }
    display(Graph);
    return 0;
}