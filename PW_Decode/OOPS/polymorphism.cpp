#include<bits/stdc++.h>
using namespace std;

class Bike{
    public:
        static int noOfBikes; // this belongs to class
        int tyreSize;
        int engineSize;
        // Constructor

        // Constructor overloading
        Bike(int tyreSize){
            this->tyreSize = tyreSize;
            cout<<"hi"<<endl;
        }
        Bike(int tyreSize,int engineSize){
            this->tyreSize = tyreSize;
            this->engineSize = engineSize;
        }
        Bike() : tyreSize(15) , engineSize(200){}

        // Function overloading
        int add(int a,int b){
            return a+b;
        }
        int add(double a,double b){
            return a+b;
        }
};

int Bike::noOfBikes = 10;

int main(){
    Bike bk1(12);
    cout<<bk1.noOfBikes<<endl;
    Bike bk2(13);
    cout<<bk2.noOfBikes<<endl;
    return 0;
} 


int Bike::noOfBikes = 10;

int main(){
    Bike bk1(12);
    cout<<bk1.noOfBikes<<endl;
    Bike bk2(13);
    cout<<bk2.noOfBikes<<endl;
    return 0;
}

int Bike::noOfBikes = 10;

int main(){
    Bike bk1(12);
    cout<<bk1.noOfBikes<<endl;
    Bike bk2(13);
    cout<<bk2.noOfBikes<<endl;
    return 0;
}