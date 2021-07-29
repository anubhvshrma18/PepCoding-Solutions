#include "bits/stdc++.h"
using namespace std;

int cnt=1;

void solution(int idx,int n,vector<bool> &used,string asf){
	if(idx==used.size()){
		cout << cnt << ".";
		cout << asf << endl;
		return;
	}

	if(used[idx]==true){
		solution(idx+1,n,used,asf);
	}
	else{
		used[idx]=true;
		solution(idx+1,n,used,asf+"("+to_string(idx)+") ");
		
		for(int i=idx+1;i<=n;i++){
			if(used[i]==false){
			    cnt++;
				used[i]=true;
				solution(idx+1,n,used,asf+"("+to_string(idx)+","+to_string(i)+") ");
				used[i]=false;
			}
		}
		used[idx]=false;
	}


}


int main(){
	int n;
	cin >> n;
	vector<bool> used(n+1,false);

	solution(1,n,used,"");
}