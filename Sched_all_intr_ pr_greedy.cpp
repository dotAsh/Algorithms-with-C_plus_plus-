#include <bits/stdc++.h>
using namespace std;
void selectActivies(vector<int> s, vector<int> f){
	int size = s.size();
	map<int,list<pair<int,int>>> a;
	int i = 0;
	a[i].push_back(make_pair(s[i],f[i]));
	int size2 = 1;
	bool t = false;
	for( int j = 1;j<size;j++){
		while(s[j] < a[i].back().second){		 
		   i++;
		   if(i == size2){
			   t = true;
			    break;
			}
		}
		a[i].push_back(make_pair(s[j],f[j]));
		if(t){
		 size2++;
		 t = false;	
		}
		i = 0;
	}
	
	for(int j = 0;j<size2;j++){
		cout<<"*****set "<<j<<" of intervals start******"<<endl;
		for(auto l = a[j].begin();l!= a[j].end();l++){
			cout<<(*l).first<<" "<<(*l).second<<endl;
		}
		cout<<"******set "<<j<<" of intervals end*****"<<endl;
	}
}

int main(){
	vector<int> s = {10,10,10,25,25,40,40,45,55,55};
	vector<int> f = {20,30,20,30,45,50,50,60,65,65};
	//greedy method
	selectActivies(s,f);
return 0;	
}

