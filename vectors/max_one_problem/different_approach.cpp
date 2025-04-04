#include<iostream>
#include<vector>
using namespace std;

int maxOnesRow(vector<vector<int>>&v){
    int maxOnes=INT16_MIN;
    int maximumOnesRow=-1;
    int columns=v[0].size();
    for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]==1){
                int number_of_ones=columns-j;
                if(number_of_ones>maxOnes){
                    maxOnes=number_of_ones;
                    maximumOnesRow=i;
                }
                break;
            }
        }
    }
    cout<<maxOnes;
    return maximumOnesRow;
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
    int result=maxOnesRow(v);
    cout<<result;
    return 0;
}