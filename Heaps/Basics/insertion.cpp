#include<iostream>
#include<vector>
using namespace std;

class Heap{
    public:
        vector<int>arr;
        Heap(){
            arr.push_back(-1);
        }

        void Heapify(int index){
            int parent = index/2;
            if(parent>0 && arr[parent]<arr[index]){
                swap(arr[parent],arr[index]);
                Heapify(parent);
            }
        }

        void insert(int key){
            arr.push_back(key);
            Heapify(arr.size()-1);
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
    return 0;
}