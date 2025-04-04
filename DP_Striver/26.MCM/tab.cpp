#include<bits/stdc++.h>
using namespace std;

void printP(int i,int j,vector<vector<int>>&s,string &ans){
    if(i==j){
        string add = 'A'+to_string(i+1);
        ans+=add;
        return;
    }
    ans+='(';
    printP(i,s[i][j],s,ans);
    printP(s[i][j]+1,j,s,ans);
    ans+=')';
}

int main(){
    int n;
    cin>>n;
    vector<int>dim(n+1);
    for(int i=0;i<=n;i++) cin>>dim[i];
    vector<vector<int>>m(n,vector<int>(n,INT_MAX));
    vector<vector<int>>s(n,vector<int>(n,-1));

    for(int i=0;i<n;i++) m[i][i]=0;

    for(int len=2;len<=n;len++){
        for(int i=0;i<=n-len;i++){
            int j = i+len-1;
            for(int k=i;k<j;k++){
                int q = m[i][k]+m[k+1][j]+dim[i]*dim[k+1]*dim[j+1];
                if(m[i][j]>q){
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }


    cout<<"Minimum cost matrix (m):"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<=j) cout<<m[i][j]<<" ";
            else cout<<"INF ";
        }
        cout<<endl;
    }
    cout<<endl;

    // split matrix
    cout<<"Split matrix (s):"<<endl;
    for(int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if(i<=j) cout<<s[i][j]<<" ";
            else cout<<"-1 ";
        }
        cout<<endl;
    }

    // printing brackets
    // can be done by using a recursive function
    string ans = "";
    printP(0,n-1,s,ans);
    cout<<ans;
    return 0;
}