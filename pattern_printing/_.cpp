#include <iostream>
using namespace std;

int max(int arr[],int len){
	int maxnum=arr[0];
	for(int i=1;i<len;i++){
		if(arr[i]>maxnum) maxnum=arr[i];		
	}
	return maxnum;
}

void count_elements(int arr[],int len){
	//hash array
    int size=max(arr,len);
	int harr[size]={0};//setting all to zeroes
	//counting and filling hash array
	for(int i=0;i<len;i++){
		harr[arr[i]]++;	
	}
	
	//printing frequencies of elements
	for(int i=0;i<len;i++){
		cout<<i<<") "<<arr[i]<<" : "<<harr[arr[i]]<<endl;	
	}
}

int main()
{
	int len;
	cout<<endl<<"size of array: ";
	cin>>len;
	int arr[len];
	for(int i=0;i<len;++i){
		cin>>arr[i];
			
	}
	count_elements(arr,len);
	return 0;
}
