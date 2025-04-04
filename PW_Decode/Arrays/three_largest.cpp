#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int max1,max2,max3;
    max1=max2=max3=v[0];
    for(int i=1;i<n;i++){
        if(v[i]>max1){
            max3=max2;
            max2=max1;
            max1=v[i];
        }
        else if(v[i]>max2){
            max3=max2;
            max2=v[i];
        }
        else if(v[i]>max3){
            max3 = v[i];
        }
    }
    cout<<max1<<" "<<max2<<" "<<max3;
    return 0;
}