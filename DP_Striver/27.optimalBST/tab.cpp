#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>key(n);
    vector<int>freq(n);
    for(int i=0;i<n;i++) cin>>key[i];
    for(int i=0;i<n;i++) cin>>freq[i];

    vector<int>pre(n);
    pre[0]=freq[0];
    for(int i=1;i<n;i++) pre[i]=pre[i-1]+freq[i];
    vector<vector<int>>cost(n,vector<int>(n,INT_MAX));
    vector<vector<int>>root(n,vector<int>(n,-1));

    for(int i=0;i<n;i++) cost[i][i]=freq[i];

    for(int len=2;len<=n;len++){
        for(int i=0;i<=n-len;i++){
            int j = i+len-1;
            for(int k=i;k<=j;k++){  // considering all possible roots
                int leftCost = (k>i)?cost[i][k-1]:0;
                int rightCost = (k<j)?cost[k+1][j]:0;
                int weight = pre[j]-(i>0?pre[i-1]:0);
                int totalCost = leftCost+rightCost+weight;
                if(totalCost<cost[i][j]){
                    cost[i][j]=totalCost;
                    root[i][j]=k;
                }
            }
        }
    }


    cout<<"Cost matrix:\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            if(i<=j)
                cout<<cost[i][j]<<" ";
            else
                cout<<"INF ";
        }
        cout<<endl;
    }
    cout<<endl;

    // Output the root matrix
    cout<<"Root matrix:\n";
    for(int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if(i<=j)
                cout<<root[i][j]<<" ";
            else
                cout<<"-1 ";
        }
        cout<<endl;
    }
    return 0;
}