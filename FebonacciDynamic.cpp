#include <bits/stdc++.h>
using namespace std;

//global array
int f[5] = {0};
int febonacci(int n){
		if((n==1)||(n==0)){
				return n;
		}
		if(f[n]== 0){
			//memoization
			//top-down dynamic
			//losing space but gaining time
				f[n]= febonacci(n-1)+febonacci(n-2);
		}
	return f[n];
	
}
int dynamicFibonacci(int n){
	f[0] = 0;
	f[1] = 1;
	//bottom-up
	//real dynamic
	for(int i = 2;i<= n;i++){
			f[i] = f[i-1] + f[i-2];
	}
	return f[n];
}
int main(){
	
	f[1] = 1;
	cout<<dynamicFibonacci(4)<<endl;
return 0;	
}

