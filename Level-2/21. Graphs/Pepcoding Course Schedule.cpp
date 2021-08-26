#include <bits/stdc++.h>
using namespace std;

void courseSchedule(vector<vector<int>> &edges,int v){
	vector<int> inD(v,0);

	vector<vector<int>> g(v);
	for(auto edge:edges){
		g[edge[1]].push_back(edge[0]);

		inD[edge[0]]++;
	}

	queue<int> q;
	for(int i=0;i<v;i++) {
		if(inD[i]==0)
			q.push(i);
	}

	vector<int> ans;

	// cout << q.size() << endl;
	while(!q.empty()) {
		int node = q.front();
		q.pop();
		ans.push_back(node);
		for(int nbr : g[node]){
			inD[nbr]--;

			if(inD[nbr]==0)
				q.push(nbr);
		}
	}
// 	reverse(ans.begin(),ans.end());
	if(ans.size()!=v){
		cout << -1 << endl;
		return;
	}
	for(auto a:ans){
		cout << a << " ";
	}
	cout << endl;

}




int main(){
	int v,e;
	cin>>v>>e;
	vector<vector<int>> edges(e,vector<int> (2));
	for(int i=0;i<e;i++){

		cin >> edges[i][0] >> edges[i][1];
	}

	courseSchedule(edges,v);
	return 0;
}