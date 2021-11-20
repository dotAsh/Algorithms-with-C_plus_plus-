#include <bits/stdc++.h>
using namespace std;
void selectActivies(vector<int> s, vector<int> f){
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> a;
	int size = s.size();
	for(int i = 0;i<size;i++){
		a.push(make_pair(f[i],s[i]));
		
	}
	vector<pair<int,int>> r;
	pair<int,int> b = a.top();
	int start = b.second;
	int end = b.first;
	a.pop();
	r.push_back(make_pair(start,end));
	while(!a.empty()){
		b = a.top();
		a.pop();
		if(b.second>= end){
				start = b.second;
				end = b.first;
				
				r.push_back(make_pair(start,end));
		}
	}
	
	for(auto itr = r.begin();itr!= r.end();itr++){
		cout<<"start: "<<(*itr).first<<" end: "<<(*itr).second<<endl;
	}
	
	
}

int main(){
	vector<int> s = {1, 3, 0, 5, 8, 5};
	vector<int> f = {2, 4, 6, 7, 9, 9};
	//greedy method
	selectActivies(s,f);
return 0;	
}

