#include<iostream>
#include<vector>
using namespace std;

int main(){    
    int size;const int N = 1e5+10;
    cout<<"Enter the size : ";
    cin>>size;
    vector<int>v(size);
    for(int i=0;i<size;i++){
        cin>>v[i];
    }
    vector<int>freq(N,0);
    for(int i=0;i<size;i++){
        freq[v[i]]++;
    }

    int q;
    cout<<"Enter number of Queries : ";
    cin>>q;
    cout<<"Enter Queries : "<<endl;
    while (q--){
        int queryelement;
        cin>>queryelement;
        cout<<freq[queryelement]<<endl;
    }
    return 0;
}
