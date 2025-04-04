#include<bits/stdc++.h>
using namespace std;
#define v 4

void floydWarshall(int dist[][v]){
    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX && dist[i][j]>(dist[i][k]+dist[k][j])){
                    dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }
    }

    cout<<"The following matrix shows the shortest "
            "distances"
            " between every pair of vertices \n";
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(dist[i][j]==INT_MAX)
                cout<<"INF"<<" ";
            else
                cout<<dist[i][j]<<"   ";
        }
        cout<<endl;
    }
}

int main(){
    int graph[v][v] = {{0,3,10,INT_MAX},
                        {INT_MAX,0,4,INT_MAX},
                        {INT_MAX,INT_MAX,0,2},
                        {INT_MAX,-1,INT_MAX,0}};
    floydWarshall(graph);
    return 0;
}