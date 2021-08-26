#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> r;

int find(int x){
	if(parent[x]==x){
		return x;
	}

	return parent[x]=find(parent[x]);
}

int minCostToSupplyWater(vector<vector<int>> &edges,int v){
	vector<pair<int,pair<int,int>>> vec;
	for(int i=0;i<edges.size();i++){
		int u=edges[i][0],v=edges[i][1],w=edges[i][2];
		vec.push_back({w,{u,v}});
	}

	parent.resize(v);
	r.resize(v);

	for (int i = 0; i < v; ++i)
	{
		parent[i]=i;
		r[i]=0;
	}

	sort(vec.begin(),vec.end(),[&](const pair<int,pair<int,int>> p1,const pair<int,pair<int,int>> p2){
		return p1.first < p2.first;
	});


	int mw=0;
	for(int i=0; i < vec.size();i++){
		int nx=vec[i].second.first;
		int ny=vec[i].second.second;
		int w=vec[i].first;

		int lx = find(nx);
		int ly = find(ny);

		if(lx!=ly){
			mw+=w;
			if(r[lx] < r[ly]){
				parent[lx]=ly;
			}
			else if(r[ly] < r[lx]){
				parent[ly]=lx;
			}
			else{
				parent[lx]=ly;
				r[ly]++;
			}
		}
	}

	return mw;
}


int main(){
	int v,e;
	cin >> v >> e;
	vector<vector<int>> edges(e,vector<int>(3));
	for(int i=0;i<e;i++){
		int u,v,w;
		cin >> u >> v >> w;
		edges[i][0]=u;
		edges[i][1]=v;
		edges[i][2]=w;
	}

	cout << minCostToSupplyWater(edges,v) << endl;
	


	return 0;
}