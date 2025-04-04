#include<iostream>
#include<vector>
using namespace std;

int leftmostRow(vector<vector<int>>&v){
    int leftmostone=-1;
    int maxOnesRow=-1;
    int j=v[0].size()-1;
    for(int i=0;i<v.size();i++){
        while(j>=0 && v[i][j]==1){
            leftmostone=j;
            j--;
            maxOnesRow=i;
        }
    }
    return maxOnesRow;
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    int result=leftmostRow(v);
    cout<<result;

    return 0;
}