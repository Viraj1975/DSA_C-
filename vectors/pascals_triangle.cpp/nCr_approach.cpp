#include<iostream>
using namespace std;

int factorial(int a){
    int ans=1;
    while(a>0){
        ans*=a;
        a--;
    }
    return ans;
}

int nCr(int n,int r){
    if(r==1){
        return n;
    }
    else if((n>0 || n==0) && r==0){
        return 1;
    }
    else{
        int num;int dem;
        num=factorial(n);
        dem=factorial(n-r)*factorial(r);
        int result=num/dem;
        return result;
    }
}

int main(){
    int rows,m;
    cout<<"Enter number of rows : ";
    cin>>rows;
    for(int i=0 ; i<rows ; i++){
        for(int j=0 ; j<rows-i-1;j++){
            cout<<" ";
        }
        for(int j=0; j<i+1;j++){
            m=nCr(i,j);
            cout<<m<<" ";
        }
        cout<<endl;
    }
    return 0;
}