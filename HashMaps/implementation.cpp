#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string,int>m;
    
    // first way of making pair
    pair<string,int>pair1 = make_pair("Viraj",3);
    m.insert(pair1);

    // second way of making pair
    pair<string,int>pair2("Rajput",2);
    m.insert(pair2);


    // Third way of making pair

    // initialisation
    m["Mera"] = 1;

    // updation
    m["Mera"] = 2;


    // search
    cout<<m["Mera"]<<"\n";
    cout<<m.at("Viraj")<<"\n";

    cout<<m["Unknown key"]<<"\n";
    cout<<m.at("Unknown key")<<"\n";

    // size
    cout<<m.size()<<"\n";

    // To check presence
    cout<<m.count("Rajput")<<endl;

    // erase
    cout<<m.erase("Mera");

    // iterator 

    unordered_map<string,int> :: iterator it = m.begin();
    while(it != m.end()){
        cout<<it->first<<" "<<it->second<<"\n";
        it++;
    }
    return 0;
}