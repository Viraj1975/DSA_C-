#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int>MySet;
    MySet.insert(2);
    MySet.insert(3);
    MySet.insert(4);
    MySet.insert(1);
    MySet.insert(5);
    auto itr1 = MySet.begin();
    auto itr2 = MySet.begin();
    itr1++;// 2 
    advance(itr2,3);// 4
    MySet.erase(itr1,itr2);
    for(auto value:MySet){
        cout<<value<<" ";
    }
    cout<<endl;
}