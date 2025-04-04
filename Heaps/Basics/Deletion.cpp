#include<iostream>
#include<vector>
using namespace std;

class Heap{
    public:
        vector<int>arr;
        Heap(){
            arr.push_back(-1);
        }

        void Heapify_insert(int index){
            int parent = index/2;
            if(parent>0 && arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                Heapify_insert(parent);
            }
        }

        void insert(int key){
            arr.push_back(key);
            Heapify_insert(arr.size()-1);
        }

        void Heapify_delete(int index){
            int LC_index = 2*index;
            int RC_index = 2*index+1;
            int largest = index;

            if(LC_index<arr.size() && arr[LC_index]>arr[largest]){
                largest = LC_index;
            }
            if(RC_index<arr.size() && arr[RC_index]>arr[largest]){
                largest = RC_index;
            }
            if(largest!=index){
                swap(arr[largest],arr[index]);
                Heapify_delete(largest);
            }
        }

        void deletion(){
            if(arr.size()==1){
                cout<<"Nothing to delete.";
                return;
            }
            arr[1] = arr[arr.size()-1];
            arr.pop_back();
            Heapify_delete(1);
        }

        void print(){
            for(int i=1;i<arr.size();i++){
                cout<<arr[i]<<" ";
            }cout<<"\n";
        }
};

int main(){
    Heap h1;
    h1.insert(6);
    h1.insert(8);
    h1.insert(4);
    h1.insert(24);
    h1.insert(10);
    h1.insert(16);
    h1.insert(60);
    h1.insert(2);

    h1.print();
    h1.deletion();
    h1.print();
    return 0;
}