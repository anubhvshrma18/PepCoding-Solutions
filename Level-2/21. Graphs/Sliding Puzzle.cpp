#include <bits/stdc++.h>
using namespace std;

string findnbrafterswap(string str,int i,int j){
    string n=str;
    swap(n[i],n[j]);
    return n;
}
int slidingPuzzle(vector<vector<int>>& board) {
    vector<vector<int>> nbr={{1,3},{0,2,4},{1,5},{0,4},{1,3,5},{2,4}};  
    
    set<string> st;
    string src="";
    string dest="123450";
    for(auto v:board){
        for(auto ch:v){
            src+=to_string(ch);
        }
    }
    
    queue<string> q;
    q.push(src);
    st.insert(src);
    
    int level=0;
    while(!q.empty()){
        int size=q.size();
        while(size--){
            string tp=q.front();
            q.pop();
            if(tp==dest){
                return level;
            }
            
            int idx=-1;
            for(int i=0;i<tp.length();i++){
                if(tp[i]=='0'){
                    idx=i;
                    break;
                }
            }
            
            // cout << idx << " ";
            
            for(int i=0;i<nbr[idx].size();i++){
                int nbri=nbr[idx][i];
                
                string swapped = findnbrafterswap(tp,idx,nbri);
                
                if(st.find(swapped)==st.end()){
                    st.insert(swapped);
                    q.push(swapped);
                }
                
            }
        }
        level++;
    }
    return -1;
}

int main(){
	int n=2,m=3;
	vector<vector<int>> vec(n,vector<int> (m));
	for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> vec[i][j];
        }
	}

	cout << slidingPuzzle(vec) << endl;
	return 0;
}