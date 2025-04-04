#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void BFS(vector<vector<int>>&adjlist,int startNode,vector<bool>&visited){
    queue<int>q1;
    q1.push(startNode);
    visited[startNode] = true;
    while(!q1.empty()){
        int x = q1.front();
        cout<<x<<" ";
        q1.pop();
        for(int neighbour: adjlist[x]){
            if(!visited[neighbour]){
                visited[neighbour] = true;
                q1.push(neighbour);
            }
        }

    }
}

void addEdge(vector<vector<int>>&v,int start,int end){
    v[start].push_back(end);
}

int main(){
    int vertices = 5;

    vector<vector<int>>adjlist(vertices);
    addEdge(adjlist,0,1);
    addEdge(adjlist,0,2);
    addEdge(adjlist,1,3);
    addEdge(adjlist,1,4);
    addEdge(adjlist,2,4);

    vector<bool>visited(vertices,false);

    BFS(adjlist,0,visited);
    return 0;
}
