#include "bits/stdc++.h"
using namespace std;
// qpsf->queen placed so far
// tq->total queen
// asf->ans so far
void queencombinationqueenchoose(vector<vector<bool>> &queens,int qpsf,int tq,int lr,int lc){
	if(qpsf==tq){
		// if(){
			for(int i=0;i<tq;i++){
				for(int j=0;j<tq;j++){
					if(queens[i][j]==true){
						cout << "q\t";
					}
					else{
						cout << "-\t";
					}
				}
				cout << endl;
			}
			cout << endl;
			
		// }
		return;
		
	}
	for(int i=lr;i<tq;i++){
		for(int j=(i==lr)?lc+1:0;j<tq;j++){
			if(queens[i][j]==false){
				queens[i][j]=true;
				queencombinationqueenchoose(queens,qpsf+1,tq,i,j);
				queens[i][j]=false;
			}
		}
	}

}

int main(){
	int n;
	cin >> n;
	vector<vector<bool>> queens(n,vector<bool>(n,false));
	queencombinationqueenchoose(queens,0,n,0,-1);
	return 0;

}