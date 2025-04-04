#include<bits/stdc++.h>
using namespace std;

int find(vector<int>&parent,int x){
    // TC : O(log*n);
    return parent[x] = (parent[x]==x)?x:find(parent,parent[x]);
}

void Union(vector<int>&parent,vector<int>&size,vector<int>&minimal,vector<int>&maximal,vector<int>&rank,int a,int b){
    a = find(parent,a);
    b = find(parent,b);
    if(a==b) return;

    if(rank[a] >= rank[b]){
        rank[a]++;
        parent[b] = a;
        size[a] += size[b];
        maximal[a] = max(maximal[a],maximal[b]);
        minimal[a] = min(minimal[a],minimal[b]);
    }
    else{
        rank[b]++;
        parent[a] = b;
        size[b] += size[a];
        maximal[b] = max(maximal[a],maximal[b]);
        minimal[b] = min(minimal[a],minimal[b]);
    }
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int>parent(n+1);
    vector<int>rank(n+1,0);
    vector<int>size(n+1,1);
    vector<int>minimal(n+1);
    vector<int>maximal(n+1);

    for(int i=0;i<=n;i++){
        parent[i]=minimal[i]=maximal[i] = i;
    }

    while(m--){
        string str;
        cin>>str;

        if(str=="union"){
            int x,y;
            cin>>x>>y;
            Union(parent,size,minimal,maximal,rank,x,y);
        }
        else{
            int x;
            cin>>x;
            x = find(parent,x);
            cout<<minimal[x]<<" "<<maximal[x]<<" "<<size[x];
        }
    }
    return 0;
}