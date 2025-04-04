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

unordered_map<int,int> Dijkstra(int src,int n){
    priority_queue<pp,vector<pp>,greater<pp>>pq;
    unordered_set<int>visited;
    vector<int>via(n+1);
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[i]=INT_MAX;
    }
    pq.push({0,src});
    mp[src] = 0;
    while(!pq.empty()){
        pp curr = pq.top();
        if(visited.count(curr.second)){
            pq.pop();
            continue;
        }
        visited.insert(curr.second);
        pq.pop();

        for(auto neighbor : graph[curr.second]){
            if(!visited.count(neighbor.first) && mp[neighbor.first]>mp[curr.second]+neighbor.second){
                pq.push({mp[curr.second]+neighbor.second,neighbor.first});
                via[neighbor.first] = curr.second;
                mp[neighbor.first] = mp[curr.second]+neighbor.second;
            }
        }
    }
    return mp;
}

int main(){
    int n,m;
    cin>>n>>m;
    graph.resize(n,list<pp>());
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        addEdge(u,v,wt);
    }
    int src;
    cin>>src;
    unordered_map<int,int>ans = Dijkstra(src,n);
    for(auto p : ans){
        cout<<p.first<<" "<<p.second<<endl;
    }
    int dest;
    cin>>dest;
    cout<<ans[dest]<<endl;
    return 0;
}