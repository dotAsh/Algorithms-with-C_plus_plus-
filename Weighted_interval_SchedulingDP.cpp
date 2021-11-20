
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Job{
    int start, finish, profit;
};



// comparator function for sort function
int compare(Job x, Job y){
    return x.finish < y.finish;
}

int p(vector<Job> arr, int i){
    for (int j=i-1; j>=0; j--){
        if (arr[j].finish <= arr[i].start){

            return j;
		}
    }
    return -1;
}

class a{
	vector<int> m;
	vector<int> pred;
	public:
	a(int size){
		m = vector<int>(size,-1);
		pred = vector<int>(size,0);
		}
	int m_wis(vector<Job> arr,int j){
		if(j==-1){
			return 0;
		}else if(m[j]==-1){
			int kkk = p(arr,j);
			if( (arr[j].profit + m_wis(arr, kkk))  > m_wis(arr,j-1)){
				m[j] = arr[j].profit + m_wis(arr,kkk);
	
				pred[j] =  kkk;
			}else{
				 m[j] = m_wis(arr,j -1);
	
				pred[j] = j-1;
			}
	
			}
		return m[j];
	}

	void wis_find_solution(vector<Job> arr, int j){
		if (j == -1){
		}else{
			int kkk = p(arr,j);
			if (pred[j] == kkk){
				cout<<"start: "<<arr[j].start<<" end: "<<arr[j].finish<<" profit: "<<arr[j].profit<<endl;
				wis_find_solution(arr,kkk);
			}else {
				wis_find_solution(arr,j-1);
			}
		}
	}

	
	int bottomUP_mwis(vector<Job> arr){
		int n = arr.size();	
		for(int  j = 0 ;j<n;j++) {
			int b;
			int f;
			if(j == 0){
				b = 0;
			}else{
				b = m[j-1];
			}
			if(p(arr,j)==-1){
				f = 0;
			}else{
				f = m[p(arr,j)];
				}
			if (arr[j].profit + f > b){
				m[j] = arr[j].profit + f;
				pred[j] = p(arr,j);
			}else {
				m[j] = b;
				pred[j] = j - 1;
			}
		}
		return m[n-1];
	}
	void bottomUP_wis_find_solution(vector<Job> arr){
		int j = arr.size() -1;
		while (j >= 0){
			if (pred[j] == p(arr, j)){
				cout<<"start: "<<arr[j].start<<" end: "<<arr[j].finish<<" profit: "<<arr[j].profit<<endl;
			}
			j = pred[j];
		}
	
	}
};

int main(){
    vector<Job> arr= { {3, 10, 20}, {1, 2, 50}, {6, 19, 100}, {2, 100, 200} };
    int n = arr.size();

    sort(arr.begin(), arr.end(), compare);
   
    a k (n);
	//cout<<"by using top-down  method"<<endl;
    //cout<<"Total profit: "<<k.m_wis(arr,n-1)<<endl;
    //k.wis_find_solution(arr,n-1);
   
    cout<<"by using bottom up or dynamic method"<<endl;
    cout<<"Total profit: "<<k.bottomUP_mwis(arr)<<endl;
    k.bottomUP_wis_find_solution( arr);
	return 0;
}

