
#include "bits/stdc++.h"
using namespace std;


/*
 * 
 take user input as follows
 number of item ex: 3
 max limit of knapsack ex: 8
 weights of each item ex: 2 8 5 
 values of each item  ex: 100 250 300
 ex:
 3
 8
 2 3 5
 10 25 30
 * */
 
bool compare(pair<double,int> p1, pair<double,int> p2){
		return p1.first>p2.first;
}
void printArr(int arr[],int size){
	for(int i = 0; i<size;i++){
			cout<<arr[i]<<" ";
		
	}
	cout<<endl;
}
int * fractinal_knapsack(int w[],int b[],int n,int maxw){
	int *x= new int [n]{0};
	vector<pair<double,int>> v;
	int currentw= 0;
	for(int i = 0;i<n;i ++){
		
			v.push_back( make_pair((double)b[i] /(double)w[i],i));
	}
	sort(v.begin(),v.end(),compare);
	
	int j = 0;
     while(currentw < maxw){
		
		int i = v[j].second;
		
		if((currentw + w[i]) <= maxw){
			
			x[i] = w[i];
		}else{
			
				x[i] = maxw - currentw;
		} 
		currentw = currentw + x[i];
		j = j + 1;
		
	}
	
	return x;
}
double returnProfit(int arr[],int w[],int b[],int size){
	double profit = 0;
	for(int i = 0; i<size;i++){
		//cout<<((double)b[i]/(double)w[i])<<endl;
		profit = profit + ((double)arr[i]*((double)b[i]/(double)w[i]));
		
	}
	return profit;
}
int main(){
	int n,maxw;
	cin>>n>>maxw;
	int w[n];
	int b[n];
	for(int i = 0; i<n ;i ++){
			int x;
			cin>>x;
			w[i] = x;
	}
	for(int i = 0; i<n ;i ++){
			int x;
			cin>>x;
			b[i] = x;
	}
	
	
	int *x = fractinal_knapsack( w, b,n,maxw);
	//printArr(x,n);
	
	cout<<"profit: "<<returnProfit(x,w,b,n)<<endl;
	
	delete []x;
	x = nullptr;
return 0;	
}

