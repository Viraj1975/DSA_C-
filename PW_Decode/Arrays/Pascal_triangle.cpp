#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>>v;
    for(int i=0;i<n;i++){
        vector<int>vsub;
        for(int j=0;j<=i;j++){
            if(j==0 || j==i){
                vsub.push_back(1);
            }
            else{
                vsub.push_back(v[i-1][j]+v[i-1][j-1]);
            } 
        }
        v.push_back(vsub);
    } 
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
           cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }   
    return 0;
}