#include<bits/stdc++.h>
using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // multimap<int,int>m;
        // for(int i=0;i<arr.size();i++){
        //     m.insert(pair<int,int>(abs(arr[i]-x),arr[i]));
        // }
        // vector<int>ans;
        // int count = 0;
        // for(auto i=m.begin();i!=m.end();i++){
        //     if(count<k){
        //         count++;
        //         ans.push_back(i->second);
        //     }
        // }
        // sort(ans.begin(),ans.end());
        // return ans;



        // Using Binary Search

        // SC : O(k)
        // TC : O(logk + k + klogk);

        vector<int>ans;
        int n = arr.size();
        if(x<=arr[0]){
            for(int i=0;i<k;i++){
                ans.push_back(arr[i]);
            }
            return ans;
        }
        if(x>=arr[n-1]){
            for(int i=n-k;i<=n-1;i++){
                ans.push_back(arr[i]);
            }
            return ans;
        }

        int start = 0;
        int end = arr.size()-1;
        int x_idx = -1;
        while(end>=start){
            int mid = start + (end-start)/2;
            if(arr[mid]==x){
                x_idx=mid;
                break;
            }
            else if(arr[mid]>x){
                end = mid - 1;
            }
            else start = mid + 1;
        }
        if(x_idx==-1){
            int lb = end;
            int hb = start;
            while((lb>=0 && hb<arr.size()) && ans.size()!=k){
                int diff1 = abs(arr[lb]-x);
                int diff2 = abs(arr[hb]-x);
                if(diff1==diff2){
                    ans.push_back(arr[lb]);
                    lb--;
                }
                else if(diff2<diff1){
                    ans.push_back(arr[hb]);
                    hb++;
                }
                else{
                    ans.push_back(arr[lb]);
                    lb--;
                }
            }
            while(lb>=0 && ans.size()!=k){
                ans.push_back(arr[lb]);
                lb--;
            }
            while(hb<=arr.size()-1 && ans.size()!=k){
                ans.push_back(arr[hb]);
                hb++;
            }
            sort(ans.begin(),ans.end());
        }
        else{
            int lb = x_idx-1;
            int hb = x_idx+1;
            ans.push_back(arr[x_idx]);
            while((lb>=0 && hb<arr.size()) && ans.size()!=k){
                int diff1 = abs(arr[lb]-x);
                int diff2 = abs(arr[hb]-x);
                if(diff1==diff2){
                    ans.push_back(arr[lb]);
                    lb--;
                }
                else if(diff2<diff1){
                    ans.push_back(arr[hb]);
                    hb++;
                }
                else{
                    ans.push_back(arr[lb]);
                    lb--;
                }
            }
            while(lb>=0 && ans.size()!=k){
                ans.push_back(arr[lb]);
                lb--;
            }
            while(hb<=arr.size()-1 && ans.size()!=k){
                ans.push_back(arr[hb]);
                hb++;
            }
            sort(ans.begin(),ans.end());
        }
    return ans;
}

int main(){
    return 0;
}
