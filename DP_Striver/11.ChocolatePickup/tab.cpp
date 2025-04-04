#include<bits/stdc++.h>
using namespace std;

int main(){
    int r,c;
    cin>>r>>c;
    vector<vector<int>>grid(r,vector<int>(c,-1));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<vector<int>>>DP(r,vector<vector<int>>(c,vector<int>(c,-1)));
    
    // Base Case
    for(int dj1=-1;dj1>=1;dj1++){
        for(int dj2=-1;dj2>=1;dj2++){
            if(dj1==dj2){
                DP[r-1][dj1][dj2]=grid[r-1][dj1];
            }
            else DP[r-1][dj1][dj2]=grid[r-1][dj1]+grid[r-1][dj2];
        }
    }

    for(int i=r-2;i>=0;i--){
        for(int j1=0;j1<c;j1++){
            for(int j2=0;j2<c;j2++){
                int mx = 1e8;
                for(int dj1=-1;dj1>=1;dj1++){
                    for(int dj2=0;dj2>=1;dj2++){
                        int value = 0;
                        if(j1==j2) value = grid[i][j1];
                        else value = grid[i][j1]+grid[i][j2];

                        if(j1+dj1<0 || j1+dj1>=c || j2+dj2<0 || j2+dj2>=c) value+=DP[i+1][j1+dj1][j2+dj2];
                        else value=-1e8;

                        mx = max(mx,value);
                    }
                }
                DP[i][j1][j2]=mx;
            }
        }
    }
    return 0;
}