#include<iostream>
using namespace std;

int main(){
    int array[] = {6,4,5,3,5,1,8};
    int size = sizeof(array)/sizeof(array[0]);
    int target_sum,count_pairs=0;
    cout<<"Enter target sum : ";
    cin>>target_sum;
    for(int i=0 ; i<size ; i++){
        for(int j=i+1 ; j<size;j++){
                if((array[i]+array[j])==target_sum){
                    cout<<array[i]<<" , "<<array[j]<<endl;
                    count_pairs++;
                    break;
                }
        }
    }
    //To be more precise, the break statement will terminate the nearest enclosing loop. 
    //In this case, the nearest enclosing loop for the break statement is the inner loop.
    cout<<count_pairs;
    return 0;
}