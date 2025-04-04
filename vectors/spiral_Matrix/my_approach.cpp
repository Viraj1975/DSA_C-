#include<iostream>
#include<vector>
using namespace std;

void spiralOrder(vector<vector<int>>&Matrix){
    int direction=0;
    int top=0;
    int bottom=Matrix.size()-1;
    int left=0;
    int right=Matrix[0].size()-1;
    while(top<=bottom && left<=right){
        if(direction==0){
            for(int col=left;col<=right;col++){
                cout<<Matrix[top][col]<<" ";
            }
            top++;
        }
        else if(direction==1){
            for(int row=top;row<=bottom;row++){
                cout<<Matrix[row][right]<<" ";
            }
            right--;
        }
        else if(direction==2){
            for(int col=right ; col>=left;col--){
                cout<<Matrix[bottom][col]<<" ";
            }
            bottom--;
        }
        else{
            for(int row=bottom;row>=top;row--){
                cout<<Matrix[row][left]<<" ";
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

}

int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>Matrix(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>Matrix[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<Matrix[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
    spiralOrder(Matrix);
    return 0;
}
