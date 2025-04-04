#include<iostream>
#include<vector>
#include<string>
using namespace std;

string longest_prefix_string(vector<string>&S){
    int result_length = S[0].size();
    int j;int n = S.size();
    for(int i=1;i<n;i++){
        int j=0;
        while(j<S[i].size() && j<S[0].size()){
            if(S[0][j]==S[i][j]){
                j++;
            }
            else break;
        }
        if(j<result_length) result_length=j;
    }
    string result = S[0].substr(0,result_length);
    return result;    
}

int main(){
    int n;
    cout<<"Enter number of strings : ";
    cin>>n;
    cout<<"Enter strings : ";
    vector<string>S;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        S.push_back(s);
    }
    cout<<"longest prefix string is ";
    cout<<longest_prefix_string(S);
    return 0;
}