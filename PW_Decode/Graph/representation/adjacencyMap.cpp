#include<bits/stdc++.h>
using namespace std;

vector<unordered_map<int,int>>graph;
int v;
void addEdge(int src,int dest,int wt,bool bi_dir = true){
    graph[src][dest] = wt;
    if(bi_dir){
        graph[dest][src] = wt;
    }
}

void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<"->";
        for(auto x : graph[i]){
            cout<<"("<<x.first<<" "<<x.second<<") , ";
        }
        cout<<endl;
    }
}

int main(){
    cin>>v;
    graph.resize(v,unordered_map<int,int>());

    int e;
    cin>>e;
    while(e--){
        int s,d,wt;
        cin>>s>>d>>wt;
        addEdge(s,d,wt,false);
    }
    display();
    return 0;
}