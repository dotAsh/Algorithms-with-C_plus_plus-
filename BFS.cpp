#include <bits/stdc++.h>
#include <fstream>

using namespace std;
void printArray(map<int,int> a,ofstream &outfile){
	for(auto i:a){
		outfile<<a[i.first]<<" ";
	}
	
}
class Graph{
	int V; 
	map<int, int> color;
	map<int, int> parent;
	map<int, int> d;
	map<int, list<int>> adj;
public:
	Graph(int V); 
	void addEdge(int v, int w);
	void BFS_visit(int s);
	void BFS();
	void display_result(){
		ofstream outfile("bfs_graph",ios::app);
	        outfile<<endl;
			outfile<<endl<<"color after bfs ";
		 printArray(color,outfile);
			outfile<<endl;
			outfile<<endl<<"parent node ";
		 printArray(parent,outfile);
			outfile<<endl;
			outfile<<endl<<"distance form source ";
		 printArray(d,outfile);
			outfile<<endl;
			outfile.close();
		}
	
	
};

Graph::Graph(int v){
	this->V = v;
}

void Graph::addEdge(int v, int w){
	adj[v].push_back(w); 
}

void Graph::BFS_visit(int s){
	list<int> queue;
	color[s] = 1;
	d[s] = 0;
	queue.push_back(s);
	list<int>::iterator i;
	while(!queue.empty()){
		s = queue.front();
		ofstream outfile("bfs_graph",ios::app);
		outfile << s << " ";
		queue.pop_front();
		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (color[*i]==0)
			{
				color[*i] = 1;
				parent[*i] = s;
				d[*i] = d[s] + 1;
				queue.push_back(*i);
			}
		}
		color[s] = 2;
	}
	
}
void Graph::BFS(){
	for (auto i:adj){
		color[i.first] = 0;
		parent[i.first] = -1;
		d[i.first] = 0;
	}
	
	
	for (auto i:adj){
		if (color[i.first] == 0){
			BFS_visit(i.first);
		}
	}
}

int main(){
	ifstream infile("graph.txt");
	if(!infile){
		cout<<"file can not be opened!"<<endl;
		}else{
			int ver,ed;
			infile>>ver>>ed;
			Graph g(ver);
			while(!infile.eof()){
				int node1,node2;
				infile>>node1>>node2;
				g.addEdge(node1,node2);
			}
			infile.close();
			
			g.BFS();
			g.display_result();
		}
	return 0;
}






