#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(vector<vector<int>>&DP,vector<int>&nums,int target,int i){
        if(target<-1000 || target>1000) return 0;
        if(i==0){
            if(target==0 && nums[0]==0) return 2;
            if(target==nums[0] || target==-nums[0]) return 1;
            return 0;
        }
        if(DP[i][target+1000]!=-1) return DP[i][target+1000];
        int add = f(DP,nums,target-nums[i],i-1);
        int sub = f(DP,nums,target+nums[i],i-1);
        return DP[i][target+1000] = add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        vector<vector<int>>DP(n,vector<int>(2001,-1));
        return f(DP,nums,target,n-1);
    }
};

int main(){
    return 0;
}