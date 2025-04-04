#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    cin>>m>>n;
    
    vector<int>DP(n,1);
    for(int i=1;i<m;i++){
        vector<int>temp;
        int prev = 1;
        temp.push_back(prev);
        for(int j=1;j<n;j++){
            int curr = prev+DP[j];
            temp.push_back(curr);
            prev = curr; 
        }
        DP = temp;
    }
    cout<<DP[m-1];
    return 0;
}


// More Optimization 

// #include <bits/stdc++.h> 
// int uniquePaths(int m, int n) {
// 	vector<int>DP(n,1);
//     for(int i=1;i<m;i++){
//         int prev = 1;
//         for(int j=1;j<n;j++){
//             int curr = prev+DP[j];
//             DP[j]=curr;
//             prev = curr; 
//         }
//     }
//     return DP[n-1];
// }