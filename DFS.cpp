
#include <bits/stdc++.h>
#include <fstream>

using namespace std;
void printArray(map<int,int> a,ofstream &outfile){
	for(auto i:a){
		outfile<<a[i.first]<<" ";
	}
}
class Graph {
		void DFS_visit(int v);
		int time;
		map<int, int> color;
		map<int, int> parent;
		map<int, int> d;
		map<int, int> f;
		map<int, list<int>> adj;
	public:
		void addEdge(int v, int w);
		void DFS();
		void display_result(){
			ofstream outfile("dfs_graph",ios::app);
	         outfile<<endl;
			outfile<<endl<<"found time ";
		  printArray(d,outfile);
			outfile<<endl;
			outfile<<endl<<"finished time ";
		  printArray(f,outfile);
			outfile<<endl;
			outfile<<endl<<"color after dfs ";
		  printArray(color,outfile);
			outfile<<endl;
			outfile<<endl<<"parent node ";
		  printArray(parent,outfile);
			outfile<<endl;
			outfile.close();
			
		}
};

void Graph::addEdge(int v, int w){
	adj[v].push_back(w); 
}

void Graph::DFS_visit(int v){
	color[v] = 1;
	
	d[v] = ++time;
	ofstream outfile("dfs_graph",ios::app);
	outfile << v << " ";
	outfile.close();
	list<int>::iterator i;
	for (i = adj[v].begin(); i != adj[v].end(); ++i){
		if(color[*i] == 0){
			parent[*i] = v;
			DFS_visit(*i);
		}
	}
	color[v] = 2;
	f[v] = ++time;
}



void Graph::DFS(){
	for (auto i:adj){
		color[i.first] = 0;
		parent[i.first] = -1;
		
	}
	time  = 0;
	for (auto i:adj){
		if (color[i.first] == 0){
			DFS_visit(i.first);
		}
	}
}



int main(){
	ifstream infile("graph.txt");
	if(!infile){
		cout<<"file can not be opened!"<<endl;
		}else{
			int node,edg;
			infile>>node>>edg; //we do not need no of node or no of edge as we have used map here!
			Graph g;
			while(!infile.eof()){
				int node1,node2;
				infile>>node1>>node2;
				g.addEdge(node1,node2);
			}
			infile.close();
			g.DFS();
			g.display_result();
		}
	return 0;
}


