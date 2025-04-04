#include<bits/stdc++.h>
using namespace std;

bool judgeSquareSum(int c) {
    int start = 0;
    int end = c;
    int sq_root = -1;
    while(end>=start){
        int mid = start + (end-start)/2;
        long long sq = (long long)mid * mid;
        if(sq==c){
            sq_root = mid;
            break;
        }
        else if(sq>c) end = mid - 1;
        else start = mid + 1;
    }
    if(sq_root==-1) sq_root = end;

    int temp = sq_root;
    while(temp>=0){
        int rem_num = c - temp*temp;
        int sq_root1 = -1;

        start = 0;
        end = rem_num;
        while(end>=start){
            int mid = start + (end-start)/2;
            long long sq = (long long)mid*mid;
            if(sq==rem_num){
                sq_root1 = mid;
                break;
            }
            else if(sq>rem_num){
                end=mid-1;
            }
            else start=mid+1;
        }
        if(sq_root1==-1) temp--;
        else return true;
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    judgeSquareSum(n);
    return 0;
}
