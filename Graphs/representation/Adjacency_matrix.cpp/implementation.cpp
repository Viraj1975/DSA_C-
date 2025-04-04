#include<vector>
#include<iostream>
using namespace std;

vector<vector<int>> CreateAdj_Matrix(vector<vector<int>>&graph,int n){
    vector<vector<int>>adjMatrix(n,vector<int>(n,0));
    for(int i=0;i<graph.size();i++){
        for(int j=0;j<graph[i].size();j++){
            if(graph[i][j]==1){
                adjMatrix[i][j]=1;
                adjMatrix[j][i]=1;
            }
        }
    }
    return adjMatrix;
}

int main(){
    vector<vector<int>>graph = {
        {},
        {},     
        {},
        {}
    };
    int num_Vertices = graph.size();
    vector<vector<int>>adj_Matrix = CreateAdj_Matrix(graph,num_Vertices);
    for(int i=0;i<adj_Matrix.size();i++){
        for(int j=0;j<adj_Matrix[i].size();j++){
            cout<<adj_Matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}