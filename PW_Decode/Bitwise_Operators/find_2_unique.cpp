#include<bits/stdc++.h>
using namespace std;

void find_2_unique(vector<int>v){
    int result = v[0];
    for(int i=1;i<v.size();i++){
        result^=v[i];
    }
    int temp = result;
    int k = 0;
    while(true){
        if((temp & 1)==1){
            break;
        }
        temp=temp>>1;
        k++;
    }
    int firstVal = 0;
    for(int i=0;i<v.size();i++){
        int num = v[i];
        if(((num>>k)&1)==1){
            firstVal^=v[i];
        }
    }
    int secondVal = result^firstVal;
    cout<<firstVal<<" "<<secondVal;
}

int main(){
    vector<int>v = {1,2,1,3,2,5};
    find_2_unique(v);
    return 0;
}