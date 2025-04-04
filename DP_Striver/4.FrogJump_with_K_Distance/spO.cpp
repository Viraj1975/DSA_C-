#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n;
    cin>>k;

    vector<int>heights(n);
    for(int i=0;i<n;i++){
        cin>>heights[i];
    }

    vector<int>spO(k,-1); // space complexity : O(k)   :  but may not be required  : we wil maitain a list 
    spO[0] = 0;
    spO[1] = abs(heights[0]-heights[1]); 
    for(int i=2;i<n;i++){
        
    }
    return 0;
}