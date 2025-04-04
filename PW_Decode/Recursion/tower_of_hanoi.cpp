#include<bits/stdc++.h>
using namespace std;

int ToH(int n,char src,char mid,char dest){
    int moves = 0;
    if(n==0) return;
    //  recursive call to move top disk from src rod to mid rod using dest rod in the call.

    moves+=ToH(n-1,src,dest,mid);
    cout<<"Move disk "<<n<<" from "<<src<<" to "<<dest<<endl;

    // Increment moves to add move when we move the nth disk from src rod to mid rod.
    moves+=1;

    //  recursive call to move top disk from mid rod to dest rod using src rod in the call.
    moves+=ToH(n-1,mid,src,dest);
    return moves;
}

int main(){
    cout<<ToH(3,'A','B','C');
    return 0;
}