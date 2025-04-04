#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    int Matrix[n][n]={0};
    int direction=0;int a=1;int top=0;
    int bottom=n-1;int left=0;int right=n-1;
    while(top<=bottom && left<=right){
        if(direction==0){
            for(int col=left;col<=right;col++){
                Matrix[top][col]=a++;
            }
            top++;
        }
        else if(direction==1){
            for(int row=top;row<=bottom;row++){
                Matrix[row][right]=a++;
            }
            right--;
        }
        else if(direction==2){
            for(int col=right ; col>=left;col--){
                Matrix[bottom][col]=a++;
            }
            bottom--;
        }
        else{
            for(int row=bottom;row>=top;row--){
                Matrix[row][left]=a++;
            }
            left++;
        }
        direction=(direction+1)%4;
        // direction == 0,1,2,3 only
        // direction == 0 -> left to right 
        // direction == 1 -> top to bottom
        // direction == 2 -> right to left
        // direction == 3 -> bottom to top
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<Matrix[i][j]<<"\t";
        }
        cout<<endl;
    }

    return 0;
}
