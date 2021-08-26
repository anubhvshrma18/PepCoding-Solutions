#include <bits/stdc++.h>
using namespace std;

vector<char> parent;
    vector<int> r;

    int find(char x){
    	if(parent[x]==x){
    		return x;
    	}

    	return parent[x]=find(parent[x]);
    }
    bool equationsPossible(vector<string>& v) {
        int n=v.size();

    	parent.resize(26);
    	r.resize(26);

    	for(int i=0;i<26;i++){
    		parent[i]=i;
    		r[i]=0;
    	}



    	for(int i=0;i<n;i++){
    		if(v[i][1]=='='){

    			char nx = v[i][0];
    			char ny = v[i][3];

    			int lx = find(nx-'a');
    			int ly = find(ny-'a');

    			if(lx!=ly){
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
    	}
        
        for(int i=0;i<n;i++){
            if(v[i][1]=='!'){
               char nx = v[i][0];
    			char ny = v[i][3];

    			int lx = find(nx-'a');
    			int ly = find(ny-'a');
                
                if(lx==ly){
                    return false;
                }
                
                
            }
        }
        return true;
        
        
    }


int main(){
	int n;
	cin >> n;
	vector<string> vec(n);
	for(int i=0;i<n;i++){
		cin >> vec[i];
	}
	
	if(equationsPossible(vec)){
		cout << "true" << endl;
	} else{
		cout << "false" << endl;		
	}

	return 0;
}