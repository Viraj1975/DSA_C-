#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> create_AdjList(vector<vector<int>>graph,int n){
    vector<vector<int>>adj_list(n);
    for(int i=0;i<n;i++){
        int u = graph[i][0];
        int v = graph[i][1];
        adj_list[u].push_back(v);
        adj_list[v].push_back(u);
    }
    return adj_list;
}

int main(){
    vector<vector<int>>graph = {{0,1},{0,2},{1,2},{1,3},{0,3}};
    int num_Vertices = graph.size();
    vector<vector<int>>adj_list = create_AdjList(graph,num_Vertices);
    for(int i=0;i<num_Vertices;i++){
        cout<<i<<"-> ";
        for(int j=0;j<adj_list[i].size();j++){
            cout<<adj_list[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}