#include<bits/stdc++.h>
using namespace std;

// O(n);
// it will run for distinct as well as unique integers.
int find_first_missing_positive(vector<int>v){
    int first_missing_positive = 0;
    for(int i=0;i<v.size();i++){
        if(v[i]<0);
        else if(i>0 && v[i]==v[i-1]);
        else if(v[i]!=first_missing_positive) return first_missing_positive;
        else first_missing_positive++;
    }
    return first_missing_positive;
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cout<<find_first_missing_positive(v);
    return 0;
}