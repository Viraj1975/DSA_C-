// #include<bits/stdc++.h>
// using namespace std;

// vector<list<int>>graph;
// int v;
// void addEdge(int src,int dest,bool bi_dir = true){
//     graph[src].push_back(dest);
//     if(bi_dir){
//         graph[dest].push_back(src);
//     }
// }

// bool bfs(int src){
//     queue<int>q;
//     vector<int>par(v,-1);
//     unordered_set<int>visited;
//     visited.clear();

//     visited.insert(src);
//     q.push(src);
//     while(not q.empty()){
//         int curr = q.front();
//         cout<<curr<<" ";
//         q.pop();
//         for(auto neighbor : graph[curr]){
//             if(visited.count(neighbor)>0 && par[curr]!=neighbor){
//                return true;
//             }
//             if(not visited.count(neighbor)){
//                 q.push(neighbor);
//                 par[neighbor] = curr;
//                 visited.insert(neighbor);
//             }
//         }
//     }
//     return false;
// }

// bool has_cycle(){
//     unordered_set<int>visited;
//     bool result = false;
//     for(int i=0;i<v;i++){
//         if(not visited.count(i)){
//             result = bfs(i);
//             if(result) return true;
//         }
//     }
//     return false;
// }

// int main(){
//     cin>>v;
//     graph.resize(v,list<int>());

//     int e;
//     cin>>e;
//     while(e--){
//         int s,d;
//         cin>>s>>d;
//         addEdge(s,d,false);
//     }
//     cout<<has_cycle();
//     return 0;
// }






#include<bits/stdc++.h>
using namespace std;

vector<list<int>>Graph;
unordered_set<int>visited;
int v;

void addEdge(int src,int dest,bool bi_dir=false){
    Graph[src].push_back(dest);
    if(bi_dir){
        Graph[dest].push_back(src);
    }
}

bool bfs(int src){
    queue<int>q;
    vector<int>par(v,-1);
    q.push(src);
    visited.insert(src);


    while(q.empty()){
        int x = q.front();
        q.pop();
        for(int neighbour : Graph[x]){
            if(visited.count(neighbour) && par[x]!=neighbour){
                return true;
            }
            if(not visited.count(neighbour)){
                q.push(neighbour);
                visited.insert(neighbour);
                par[neighbour]=x;
            }
        }
    }
    return false;
}

bool has_cycle(){
    for(int i=0;i<v;i++){
        if(not visited.count(i)){
            bool res = bfs(i);
            if(res) return true;
        }
    }
    return false;
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
    cout<<has_cycle();
    return 0;
}