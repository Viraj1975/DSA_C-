#include<iostream>
#include<vector>
using namespace std;

int main(){
    int sum_even=0,sum_odd=0;
    vector<int>v(6);
    for(int i=0 ; i<6 ; i++){
        cin>>v[i];
    }
    for(int i=0 ; i<6 ; i++){
        cout<<v[i]<<endl;
    }

    for(int i=0 ; i<6 ; i++){
        if(i%2==0){
            sum_even+=v[i];
        }
        else{
            sum_odd+=v[i];
        }
    }

    cout<<sum_even;
    cout<<sum_odd;
    cout<<"difference : "<<(sum_even-sum_odd);

    return 0;
}