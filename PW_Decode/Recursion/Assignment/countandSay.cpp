#include<bits/stdc++.h>
using namespace std;

string countString(int n){
    if(n==1){
        return "1";
    }
    string str = countString(n-1);
    string result = "";
    int count = 1;
    for(int i=1;i<=str.size();i++){
        if(i<str.size() && str[i-1]==str[i]){
            count++;
        }
        else{
            result+=to_string(count)+str[i-1];
            count=1;
        }
    }
    return result;
}

int main(){
    cout<<countString(5);
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// string countString(int n) {
//     if (n == 1) {
//         return "1";
//     }
//     string prevStr = countString(n - 1);
//     string result = "";
//     int count = 1;

//     for (int i = 1; i <= prevStr.size(); i++) {
//         if (i < prevStr.size() && prevStr[i] == prevStr[i - 1]) {
//             count++;
//         } else {
//             result += to_string(count) + prevStr[i - 1];
//             count = 1;
//         }
//     }
//     return result;
// }

// int main() {
//     cout << countString(4);
//     return 0;
// }
