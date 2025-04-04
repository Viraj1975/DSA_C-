#include<bits/stdc++.h>
using namespace std;

int find(int x,vector<int>&parent){
    return parent[x] = (parent[x]==x)?x:find(parent[x],parent);
}

bool Union(vector<int>&parent,vector<int>&rank,int x,int y){
    x = find(x,parent);
    y = find(y,parent);

    if(x==y) return true;
    if(rank[x]>=rank[y]){
        rank[x]++;
        parent[y]=x;
    }
    else{
        rank[y]++;
        parent[x]=y;
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<int>parent(n);
    vector<int>rank(n+1,0);

    for(int i=0;i<n;i++) parent[i]=i;

    int m;
    cin>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        if(Union(parent,rank,x,y)){
            cout<<"Cycle Detected";
            break;
        }
    }
    return 0;
}