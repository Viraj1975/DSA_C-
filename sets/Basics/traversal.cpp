#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int>MySet;
    MySet.insert(2);
    MySet.insert(3);
    MySet.insert(4);
    MySet.insert(1);
    set<int>::iterator itr;
    // for(itr = MySet.begin();itr!=MySet.end();itr++){
    //     cout<<*itr<<" ";
    // }cout<<endl;

    for(auto value:MySet){
        cout<<value<<" ";
    }
    cout<<endl;
}