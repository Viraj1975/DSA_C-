#include<iostream>
using namespace std;

int main(){
    int rows,columns;
    cin>>rows>>columns;
    bool array[rows][columns];
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
                cin>>array[i][j];
        }
    }
    int count_element[rows];
    int count_one;
    for(int i=0;i<rows;i++){
        count_one=0;
        for(int j=0;j<columns;j++){
            if(array[i][j]==1){
                count_one++;
            }
        }
        count_element[i]=count_one;
    }
    int max_index=0;
    int max=count_element[max_index];
    for (int i = 0; i < rows; i++){
        if(count_element[i]>max){
            max=count_element[i];
            max_index=i;
        }
    }
    if(max!=0) cout<<"Max number of one's are "<<max<<" and they are present in row number "<<max_index;
    else cout<<"there are no zeros in the 2D array ";
    return 0;
}