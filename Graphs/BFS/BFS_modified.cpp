#include<bits/stdc++.h>
using namespace std;

void BFSHelper(int** edges,int V);
void printBFS(int** edges,int startNode,int* visited,int V);
void addEdge(int** edges,int v,int w){
    edges[v][w]=1;
}

void printBFS(int** edges,int startNode,int* visited,int V){
    if(V==0) return;
    queue<int>q;
    q.push(startNode);
    visited[startNode] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout<<x<<" ";
        for(int i=0;i<V;i++){
            if(edges[x][i]==1){
                if(visited[i]==0){
                    visited[i]=1;
                    q.push(i);
                }
            }
        }
    }
}

void BFSHelper(int** edges,int V){
    if(V==0) return;
    int* visited = new int[V];
    for(int i=0;i<V;i++){
        visited[i]=0;
    }
    for(int i=0;i<V;i++){
        if(visited[i]==0){
            printBFS(edges,i,visited,V);
        }
    }

}

int main(){
    int V = 5;
    int E = 6;
    if(E==0){
        for(int i=0;i<V;i++){
            cout<<i<<" ";
        }
    }
    int** edges = new int*[V];
    for(int i=0;i<V;i++){
        edges[i] = new int[V];
        for(int j=0;j<V;j++){
            edges[i][j]=0;
        }
    }

    addEdge(edges, 0, 4); 
	addEdge(edges, 1, 2); 
	addEdge(edges, 1, 3); 
	addEdge(edges, 1, 4); 
	addEdge(edges, 2, 3); 
	addEdge(edges, 3, 4); 

	BFSHelper(edges, V); 
    return 0;
}