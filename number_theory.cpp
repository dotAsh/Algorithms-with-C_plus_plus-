
#include <bits/stdc++.h>
using namespace std;
bool primeOrNot(int n) { 
	if (n < 2) return false;
	for (int x = 2; x*x <= n; x++) {
		if (n%x == 0) return false;
	}
	return true;
}

vector<int> Primefactors(int n) {
	vector<int> f;
	for (int x = 2; x*x <= n; x++) {
		while (n%x == 0) {
			f.push_back(x);
			n /= x;
		}
	}
	if (n > 1) f.push_back(n);
	return f;
}

vector<int> factors(int n){
	vector<int>f;
	for(int i = 1;i<=sqrt(n);i++){
			if(n%i == 0){
				if(n/i == i){
					f.push_back(i);
				}else{
					f.push_back(i);
					f.push_back(n/i);
				}
			}
	}
	sort(f.begin(),f.end());
	return f;
}

template <class t> 
void printVector(vector<t> a){//for printing vector
	for(int i = 0; i<(int)a.size();i++){
			cout<<a[i]<<" ";
	}
	cout<<endl;
}

int gcd(int a, int b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a%b);
}
vector<int> SoE_algo(int n){
	vector<int> sieve(n+1,0);
	sieve[0] = -1;
	sieve[1] = -1;
	for (int x = 2; x*x <= n; x++) {
		if (sieve[x]){ 
			continue;
		}
		for (int u = x*x; u <= n; u += x) {
			sieve[u] = x;
		}
	}
	return sieve;
}

int npfs(int n) {//no of prime factors
	int k = 0;
	for (int x = 2; x*x <= n; x++) {
		while (n%x == 0) {
			k++;
			n /= x;
		}
	}
	if (n > 1) {
			k++;
	}
	return k;
}
void simpleSieve(int limit, vector<int> &prime){
	vector<bool> mark(limit + 1, true);
	for (int p=2; p*p<limit; p++){
		if (mark[p] == true){
			for (int i=p*p; i<limit; i+=p){
				mark[i] = false;
			}
		}
	}
	for (int p=2; p<limit; p++){
		if(mark[p] == true){
			prime.push_back(p);
		}
	}
}


void segmentedSieve(int n){
	int limit = floor(sqrt(n))+1;
	vector<int> prime;
	prime.reserve(limit);
	simpleSieve(limit, prime);
	int low = limit;
	int high = 2*limit;
	while (low < n){
		if (high >= n)
		high = n;
		bool mark[limit+1];
		memset(mark, true, sizeof(mark));
		for (int i = 0; i < int(prime.size()); i++){
			int loLim = floor(low/prime[i]) * prime[i];
			if (loLim < low){
				loLim += prime[i];
			}
			for (int j=loLim; j<high; j+=prime[i]){
				mark[j-low] = false;
			}
		}
		for (int i = low; i<high; i++){
			if (mark[i - low] == true){
				cout << i << " ";
			}
		}
		low = low + limit;
		high = high + limit;
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	//vector<int> v = factors(84);
	//printVector(v);
	
	//v = Primefactors(84);
	//printVector(v);
	
	
	//vector<int> sieve = SoE_algo(1000);
	//printVector(sieve);
	
	//int n = 100;
	//cout << "Primes smaller than " << n << " : ";
	//segmentedSieve(n);
	
	
return 0;	
}
 

