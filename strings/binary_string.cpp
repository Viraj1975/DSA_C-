#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

// time complexity : O(n) where n is the length of binary string.
// space complexity : O(1).

int max_1s(string &s,int k){
    int max_length=0;
    int start=0;int end=0;int n = s.size();
    int zero_count=0;
    for(int end=0;end<n;end++){
        if(s[end]=='0'){
            zero_count++;
        }
        while(zero_count>k){
            if(s[start]=='0'){
                zero_count--;
            }
            start++;
        }
        max_length=max(max_length,end-start+1);
    }
    return max_length;
}

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    cout<<max_1s(s,k);
    return 0;
}