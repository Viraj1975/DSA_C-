#include<iostream>
using namespace std;

int main(){
    int array[] = {1,4,5,3,0,5,2,8};
    int size = sizeof(array)/sizeof(array[0]);
    int target_sum,count_triplets=0;
    cout<<"Enter target sum : ";
    cin>>target_sum;
    for(int i=0 ; i<size ; i++){
        for(int j=i+1 ; j<size;j++){
            for(int k=j+1 ; k<size ; k++){
                if((array[i]+array[j]+array[k])==target_sum){
                    cout<<array[i]<<" , "<<array[j]<<" , "<<array[k]<<endl;
                    count_triplets++;
                    break;
                }
            }    
        }
    }
    cout<<count_triplets;
    return 0;
}