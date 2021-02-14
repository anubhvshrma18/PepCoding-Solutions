#include<bits/stdc++.h>
using namespace std;

vector <string> getMazePathJump(int sr,int sc,int dr,int dc){
    //base case
    if(sr==dr && sc==dc){
        vector<string> base;
        base.push_back("");
        return base;
    }
    vector<string> output;
    if(sc<=dc){   
        //for jumping horizontally
        for(int jump=1;sc+jump<=dc;jump++){
            vector<string> hrjump= getMazePathJump(sr,sc+jump,dr,dc); //faith
            string j=to_string(jump);//coverting the no of jump into string
            for(int i=0;i<hrjump.size();i++){
                output.push_back("h"+j+hrjump[i]);
            }
        }  
    }
    if(sr<=dr){
        //for jumping vertically
        for(int i=1;sr+i<=dr;i++){
            vector<string> vcjump= getMazePathJump(sr+i,sc,dr,dc);//faith
            string s=to_string(i);//coverting the no of jump into string
            for(int j=0;j<vcjump.size();j++){
                output.push_back("v"+s+vcjump[j]);
            }
        }   
    }

    if(sr<=dr || sc<=dc){
        //for jumping diagonally
        for(int i=1;sr+i<=dr && sc+i<=dc;i++){
            vector<string> djump= getMazePathJump(sr+i,sc+i,dr,dc);//faith
            string s=to_string(i);//coverting the no of jump into string
            for(int j=0;j<djump.size();j++){
                output.push_back("d"+s+djump[j]);
            }
        }
    }
    
    
    return output;
}
//function to display path
void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<string> result=getMazePathJump(0,0,n-1,m-1);
    display(result);
}