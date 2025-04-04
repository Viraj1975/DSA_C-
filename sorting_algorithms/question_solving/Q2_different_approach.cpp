#include<bits/stdc++.h>
using namespace std;

// using selection sort
void sort_in_lexicographical_order(char Fruit[][60],int size){
    for (int i=0;i<size-1;i++){
        int index=i;
        for(int j=i+1;j<size;j++){
            if(strcmp(Fruit[index],Fruit[j])>0){
                    index=j;
            }
        }
        if(index!=i) swap(Fruit[i],Fruit[index]);
    }
    return;
}

int main(){
    char Fruit[][6]={"papaya","lime","watermelon","apple","mango","kiwi"};
    int n=sizeof(Fruit)/sizeof(Fruit[0]);
    sort_in_lexicographical_order(Fruit,n);
    for (int i=0;i<n;i++){
        cout<<Fruit[i]<<" ";
    }
    cout<<endl;
    return 0;
}