#include "bits/stdc++.h"
using namespace std;
// qpsf->queen placed so far
// tq->total queen
// asf->ans so far
void queenpermutation(vector<bool> &queens,int qpsf,int N,string asf,int r,int c){
	if(r==N){
		if(qpsf==N){
			cout << asf+"\n" << endl;
		}
		return;
	}

	for(int q=0;q<N;q++){
		if(queens[q]==false){
			queens[q]=true;
			if(c==N-1){
				queenpermutation(queens,qpsf+1,N,asf+"q"+to_string(q+1)+"\n",r+1,0);
			}
			else{
				queenpermutation(queens,qpsf+1,N,asf+"q"+to_string(q+1)+"\t",r,c+1);
			}
			queens[q]=false;
		}
	}
	if(c==N-1){
		queenpermutation(queens,qpsf,N,asf+"-\n",r+1,0);	
	}
	else{
		queenpermutation(queens,qpsf,N,asf+"-\t",r,c+1);
	}
	
}

int main(){
	int n;
	cin >> n;
	vector<bool> queens(n,false);
	queenpermutation(queens,0,n,"",0,0);
	return 0;

}