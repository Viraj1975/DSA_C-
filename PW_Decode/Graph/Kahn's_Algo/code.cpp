// leetcode 210 / 207
// kahn's algorithm

#include<bits/stdc++.h>
using namespace std;

vector<list<int>>Graph;
int v;

void addEdge(int src,int dest,bool bi_dir=false){
    Graph[src].push_back(dest);
    if(bi_dir){
        Graph[dest].push_back(src);
    }
}

void topoBFS(){
    vector<int>indegree(v,0);
    for(int i=0;i<v;i++){
        for(int neighbour : Graph[i]){
            indegree[neighbour]++;
        }
    }

    queue<int>q;
    unordered_set<int>visited;

    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
            visited.insert(i);
        }
    }

    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout<<x<<" ";
        for(int y : Graph[x]){
            if(not visited.count(y)){
                indegree[y]--;
                if(indegree[y]==0){
                    q.push(y);
                    visited.insert(y);
                }
            }
        }
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
    topoBFS();
    return 0;
}