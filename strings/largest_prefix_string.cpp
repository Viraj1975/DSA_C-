#include<iostream>
#include<vector>
#include<string>
using namespace std;

void sort_string(vector<string>&S){
    int n = S.size();
    for(int i=0;i<n-1;i++){
        int index = i;
        for(int j=i+1;j<n;j++){
            if(S[j].compare(S[index])<0){
                index=j;
            }
        }
        if(index!=i) swap(S[i],S[index]);
    }
}

string longest_prefix_string(vector<string>&S){
    sort_string(S);
    string result = "";
    int i=0;int j=0;int n = S.size();
    while(i<S[0].size() && j<S[n-1].size()){
        if(S[0][i]==S[n-1][j]){
            result+=S[0][i];
            i++;j++;
        }
        else{
            break;
        }
    }
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