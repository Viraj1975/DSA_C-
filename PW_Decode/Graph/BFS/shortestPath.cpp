// #include<bits/stdc++.h>
// using namespace std;

// vector<list<int>>graph;
// unordered_set<int>visited;
// int v;
// void addEdge(int src,int dest,bool bi_dir = true){
//     graph[src].push_back(dest);
//     if(bi_dir){
//         graph[dest].push_back(src);
//     }
// }

// void bfs(int src,vector<int>&dist){
//     queue<int>q;
//     visited.clear();

//     dist.resize(v,INT_MAX);
//     dist[src]=0;
//     visited.insert(src);
//     q.push(src);
//     while(not q.empty()){
//         int curr = q.front();
//         cout<<curr<<" ";
//         q.pop();
//         for(auto neighbour : graph[curr]){
//             if(not visited.count(neighbour)){
//                 q.push(neighbour);
//                 visited.insert(neighbour);
//                 dist[neighbour] = dist[curr]+1;
//             }
//         }
//     }
    
// }

// int main(){
//     cin>>v;
//     graph.resize(v,list<int>());
//     visited.clear();

//     int e;
//     cin>>e;
//     while(e--){
//         int s,d;
//         cin>>s>>d;
//         addEdge(s,d,false);
//     }
//     int src;
//     cin>>src;
//     vector<int>dist;
//     bfs(src,dist);
//     cout<<endl;
//     for(int i=0;i<dist.size();i++){
//         cout<<dist[i]<<" ";
//     }
//     return 0;
// }





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
    visited.insert(src);
    dist.resize(v,INT_MAX);
    dist[src] = 0;

    while(!q.empty()){
        int x = q.front();
        cout<<x<<" ";
        q.pop();
        for(int neighbour : Graph[x]){
            if(not visited.count(neighbour)){
                visited.insert(neighbour);
                q.push(neighbour);
                dist[neighbour] = dist[x]+1;
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

    int src;
    cin>>src;
    vector<int>dist;
    ShortestPath(src,dist);
    // dist array will have distance of every vertex from the source vertex
    return 0;
}