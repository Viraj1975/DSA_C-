#include<bits/stdc++.h>
using namespace std;
vector<list<pair<int,int>>>graph;
int v;

void addEdge(int src,int dest,int wt,bool bi_dir=false){
    graph[src].push_back({dest,wt});
    if(bi_dir){
        graph[dest].push_back({src,wt});
    }
}

vector<int> BF(int src){
    vector<int>dist(v,INT_MAX);
    dist[src]=0;

    for(int i=0;i<v-1;i++){
        for(int u=0;u<v;u++){
                for(auto ngh:graph[u]){
                    if(dist[u]!=INT_MAX && dist[ngh.first]>dist[u]+ngh.second){
                        dist[ngh.first]=dist[u]+ngh.second;
                    }
                }
        }
    }
    for(int u=0;u<v;u++){
        for(auto ngh:graph[u]){
            if(dist[u]!=INT_MAX && dist[ngh.first]>dist[u]+ngh.second){
                dist[ngh.first]=dist[u]+ngh.second;
                return {-1};
            }
        }
    }
    return dist;
}

int main(){
    cin>>v;
    int e;
    cin>>e;
    graph.resize(v);
    while(e--){
        int src,dest,wt;
        cin>>src>>dest>>wt;
        addEdge(src,dest,wt);
    }
    int src;
    cin>>src;
    vector<int>ans=BF(src);
    if(ans.size()==1 && ans[0]==-1) {
        cout<<"Negative weight cycle detected.\n";
    }else{
        cout<<"Shortest distances from source vertex "<<src<<":\n";
        for(int i=0;i<v;i++){
            if(ans[i]==INT_MAX){
                cout<<"Vertex "<<i<<": Infinity\n";
            }else{
                cout<<"Vertex "<<i<<": "<<ans[i]<<"\n";
            }
        }
    }

    return 0;
}