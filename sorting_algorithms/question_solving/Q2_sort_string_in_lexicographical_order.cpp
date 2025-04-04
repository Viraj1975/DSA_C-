#include<iostream>
#include<string>
#include<vector>
using namespace std;

void sort_in_lexicographical_order(vector<string>&Fruits){
    for(int i=0;i<Fruits.size();i++){
        bool swapped=false;
        for(int j=0;j<Fruits.size()-i-1;j++){
            if(Fruits[j].compare(Fruits[j+1])>0){
                swap(Fruits[j],Fruits[j+1]);
                swapped=true;
            }
        }
        if(!swapped) return;
    }
    return;
}

int main(){
    vector<string>Fruits={"papaya","lime","watermelon","apple","mango","kiwi"};
    sort_in_lexicographical_order(Fruits);
    for (int i=0;i<Fruits.size();i++){
        cout<<Fruits[i]<<" ";
    }
    
    return 0;
}