#include<iostream>
#include<set>
#include<unordered_set>
using namespace std;

int main(){
    unordered_set<int>MySet;
    MySet.insert(2);
    MySet.insert(3);
    MySet.insert(4);
    MySet.insert(1);

    cout<<MySet.size()<<endl;

    unordered_set<int> :: iterator it = MySet.begin();
    for(it = MySet.begin();it!=MySet.end();it++){
        cout<<*it<<endl;
    }

    MySet.insert(2);

    cout<<MySet.size();
}