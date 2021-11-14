
#include <bits/stdc++.h>
using namespace std;

void swap(int &x, int &y){
	int temp = x;
	x = y; 
	y = temp;
}

void printArray(int a[], int size){
	for(int i = 0; i<size;i++){
		cout<<*(a+i)<<" ";
	}
	cout<<endl;
}

void bubbleSort(int a[],int size){
	int n = size;
	int newn;
	while(n>1){
		newn = 0;
		for(int j = 1;j<n;j++){
			if(a[j]<a[j-1]){
				swap(a[j],a[j-1]);
				newn = j;
				}
			}
		n = newn;
	}
}	
int main(){
	int a [] = {7,3,8,12,10,1,4,5};
	int size = sizeof(a)/sizeof(a[0]);
	printArray(a,size);
	bubbleSort(a,size);
	printArray(a,size);
	return 0;
}
