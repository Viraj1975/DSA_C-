#include<bits/stdc++.h>
using namespace std;

class Bike{
    public:
        static int noOfBikes; // this belongs to class
        int tyreSize;
        int engineSize;
        // Constructor

        // Bike(int tyreSize){
        //     this->tyreSize = tyreSize;
        //     cout<<"hi"<<endl;
        // }

        // Initialisation list

        Bike(int ts,int es = 200) : tyreSize(ts) , engineSize(es){}

        // Destructor
        ~Bike(){
            cout<<"bye"<<endl;
        }

        // static methods will only access no of bikes because it will be there even before objects are created and
        //  non static variables will be created after object is instantiated
        
        // change in static variables and functions will affect all the objects; 
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