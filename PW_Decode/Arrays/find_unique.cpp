#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(int i=1;i<n;i++){
        int count = 0;
        for(int j=0;j<n;j++){
            if(v[i]==v[j] && i!=j){
                count++;
            }
        }
        if(count==0){
            cout<<v[i];
            break;
        }
    }
    return 0;
}