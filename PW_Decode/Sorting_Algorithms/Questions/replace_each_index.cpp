#include<bits/stdc++.h>
using namespace std;

float max(float a,float b){
    if(a>=b) return a;
    else return b;
}

float min(float a,float b){
    if(a<b) return a;
    else return b;
}

int find_k(vector<int>v){
    float kmax = FLT_MAX;
    float kmin  = FLT_MIN;
    bool flag = true;
    for(int i=0;i<v.size()-1;i++){
        if((v[i+1]-v[i])>=0){
            kmax = min(kmax,(v[i]+v[i+1])/2);
        }
        else{
            kmin = max(kmin,(v[i]+v[i+1])/2);
        }
        if(kmax<kmin){
            flag = false;
            break;
        }
    }
    if(flag==false) cout<<-1;
    else if(kmin==kmax){
        if(kmin-int(kmin)==0){
            cout<<"There exists only one value of k : "<<kmin;
        }
        else cout<<-1;
    }
    else{
        if(kmin-(int)kmin>0){
            kmin = (int)kmin + 1;
        }
        cout<<"Range of k is : "<<kmin<<" "<<(int)kmax;
    }
    return kmax - kmin;
}

int main(){
    vector<int>v = {5,3,10,3};
    cout<<find_k(v);
    return 0;
}