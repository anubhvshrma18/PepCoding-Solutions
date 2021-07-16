#include "bits/stdc++.h"
using namespace std;

void queencombinationbox(int r,int c,int qpsf,int tq,string asf){
	if(r==tq){
		if(qpsf==tq){
			cout << asf << endl;
		}
		return;
	}
	
	if(c==tq-1){
		queencombinationbox(r+1,0,qpsf+1,tq,asf+"q\n");
		queencombinationbox(r+1,0,qpsf,tq,asf+"-"+"\n");
	}
	else{
		queencombinationbox(r,c+1,qpsf+1,tq,asf+"q");
		queencombinationbox(r,c+1,qpsf,tq,asf+"-");
	}	


}

int main(){
	int n;
	cin >> n;
	queencombinationbox(0,0,0,n,"");
	return 0;

}