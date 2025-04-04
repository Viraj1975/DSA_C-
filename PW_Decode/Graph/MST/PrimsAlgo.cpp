#include<bits/stdc++.h>
#define ll long long int
#define pp pair<int,int>
using namespace std;

vector<list<pp>>graph;
void addEdge(int a,int b,int wt,bool bi_dir=true){
    graph[a].push_back({b,wt});
    if(bi_dir){
        graph[b].push_back({a,wt});
    }
}

ll prims(int src,int n){
    unordered_map<int,int>mp; // vertex,dist pair 
    unordered_set<int>visited;
    priority_queue<pp,vector<pp>,greater<pp>>pq;  // dist,vertex
    vector<int>parent(n);
    for(int i=0;i<n;i++) parent[i]=i;

    int total_count = 0;
    ll result = 0;

    for(int i=0;i<n;i++){
        mp[i]=INT_MAX;
    }
    mp[src]=0;
    pq.push({0,src});
    while(total_count<n && !pq.empty()){
        pp curr = pq.top();
        if(visited.count(curr.second)){
            pq.pop();
            continue;
        }
        total_count++;
        result+=curr.first;
        visited.insert(curr.second);
        pq.pop();

        for(auto neighbour:graph[curr.second]){
            if(not visited.count(neighbour.first) && mp[neighbour.first]>neighbour.second){
                parent[neighbour.first] = curr.second;
                mp[neighbour.first] = neighbour.second;
                pq.push({neighbour.second,neighbour.first});
            }
        }
    }
    return result;
}

int main(){
    int n,m;
    cin>>n>>m;
    graph.resize(n+1,list<pp>());
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        addEdge(u,v,wt);
    }
    int src;
    cin>>src;
    cout<<prims(src,n);
    return 0;
}