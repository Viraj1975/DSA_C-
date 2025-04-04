#include<bits/stdc++.h>
using namespace std;

class Edge{
    public:
        int src;
        int dest;
        int wt;
};

int find(int x,vector<int>&parent){
    return parent[x] = (parent[x]==x)?x:find(parent[x],parent);
}

void Union(vector<int>&parent,vector<int>&rank,int a,int b){
    a = find(a,parent);
    b = find(b,parent);

    if(rank[a]>=rank[b]){
        rank[a]++;
        parent[b]=a;
    }
    else{
        rank[b]++;
        parent[a]=b;
    }
}

bool cmp(Edge e1,Edge e2){
    return e2.wt>e1.wt;
}

int Kruskal(vector<Edge>&input,int v,int e){
    sort(input.begin(),input.end(),cmp);
    vector<int>parent(v);
    vector<int>rank(v,1);

    for(int i=0;i<v;i++){
        parent[i]=i;
    }

    int EdgeCount = 0;
    int n = input.size();
    int i = 0;
    int ans = 0;
    while(EdgeCount<n-1 && i<n){
        Edge curr = input[i];
        int srcPar = find(curr.src,parent);
        int destPar = find(curr.dest,parent);

        if(srcPar!=destPar){
            Union(parent,rank,srcPar,destPar);
            ans+=curr.wt;
            EdgeCount++;
        }
        i++;
    }
    return ans;
}


int main(){
    int v,e;
    cin>>v>>e;
    
    vector<Edge>input(e);
    for(int i=0;i<v;i++){
        cin>>input[i].src>>input[i].dest>>input[i].wt;
    }
    cout<<Kruskal(input,v,e);
    return 0;
}