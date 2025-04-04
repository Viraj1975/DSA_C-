#include<iostream>
#include<vector>
using namespace std;

int main(){
    // using for loop 

    vector<int>v;

    // taking input 
    for(int i=0 ; i<5 ; i++){
        int element ;
        cin>>element;
        v.push_back(element);
    }

    // printing 
    for(int i=0 ; i<v.size() ; i++){
        cout<<v[i];
    }


    // for each loop 

    for(int element:v){
        cout<<element<<endl;
    }
    
    // while loop

    int index=0;
    while(index<v.size()){
        cout<<v[index++]<<endl;
    }
    return 0;
}
