#include <bits/stdc++.h>
using namespace std;

vector<string> items{"+-","-+","XX"};

bool countValid(vector<int> &top,vector<int> &left,vector<int> &right,vector<int> &bottom,vector<vector<char>> &arr){
  for (int j = 0; j < arr[0].size(); j++) {
        int p = 0;
        int m = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i][j] == '+') {
                p++;
            } else if (arr[i][j] == '-') {
                m++;
            }
        }

        if (top[j] != -1 && top[j] != p) {
            return false;
        }
        if (bottom[j] != -1 && bottom[j] != m) {
            return false;
        }
    }


    //row traversal -> left, right
    for (int i = 0; i < arr.size(); i++) {
        int p = 0;
        int m = 0;
        for (int j = 0; j < arr[0].size(); j++) {
            if (arr[i][j] == '+') {
                p++;
            } else if (arr[i][j] == '-') {
                m++;
            }
        }

        if (left[i] != -1 && left[i] != p) {
            return false;
        }
        if (right[i] != -1 && right[i] != m) {
            return false;
        }
    }

  return true;
}


void print(vector<vector<char>> &arr) {
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j < arr[0].size(); j++) {
      cout << arr[i][j] <<  " ";
    }
    cout << endl;
  }
}
bool isItSafe(vector<vector<char>> &arr,int r,int c,string item,char marker){
  char ch1 = item[0];
  char ch2 = item[1];
  if (item=="XX") {
      return true;
  }
  if(marker == 'h'){
    // to check ch1 visibility -> sign wise

    int row=r;
    int col=c;
    if((row>0 && arr[row-1][col] == ch1) || (col>0&&arr[row][col-1]==ch1)){
      return false;
    }
    // to check ch2 visibility -> sign wise
    row=r;
    col=c+1;
    if((row>0 && arr[row-1][col] == ch2) || (col+1<arr[0].size() && arr[row][col+1]==ch2)){
      return false;
    }
  }
  else{
    int row=r;
    int col=c;
    if((row>0 && arr[row-1][col] == ch1) || (col>0&&arr[row][col-1]==ch1) || (col+1<arr[0].size() && arr[r][c+1]==ch1)){
      return false;
    }

    row=r+1;
    col=c;
    if((col>0 && arr[row][col-1] == ch2)){
      return false;
    }
  }

  return true;
}

bool solution(vector<vector<char>> &arr,vector<int> &top,vector<int> &left,vector<int> &right,vector<int> &bottom,
  vector<vector<char>> &ans ,int r,int c){
  if(c==arr[0].size()){
    // cout << "ans" << endl;
    r+=1;
    c=0;
  }

  if(r==arr.size()){
    // cout << "oo" << endl;
    if(countValid(top,left,right,bottom,ans)==true){
      // cout << "anssss" << endl;
      print(ans);
      return true;
    }
    return false;
  }

  char ch = arr[r][c];
  
  if(ch == 'L'){
    // item -> "+-"
    for(int i=0;i<3;i++){
      string item=items[i];
      if(isItSafe(ans,r,c,item,'h')){
      // place
        ans[r][c]=item[0];
        ans[r][c+1]=item[1];
        bool isAns=solution(arr,top,left,right,bottom,ans,r,c+2);

        ans[r][c]='e';
        ans[r][c+1]='e';
        if (isAns == true) {
            return true;
        }
      }
    }
          
  } else if(ch == 'T'){
    // item -> "+-"
    for(int i=0;i<3;i++){
      string item=items[i];
      if(isItSafe(ans,r,c,item,'v')){
      // place
        ans[r][c]=item[0];
        ans[r+1][c]=item[1];
        bool isAns = solution(arr,top,left,right,bottom,ans,r,c+1);

        ans[r][c]='e';
        ans[r+1][c]='e';

        if (isAns == true) {
            return true;
        }

      }
    }
    
  } else{
    bool isAns =solution(arr,top,left,right,bottom,ans,r,c+1);
    if (isAns == true) {
        return true;
    }
  }

  return false;
}



int main(){
  int m,n;
  cin>> m >> n;
  vector<vector<char>> arr(m,vector<char>(n));
  for(int i=0;i<m;i++){
    string s;
    cin >> s;
    for(int j=0;j<n;j++){
      arr[i][j]=s[j];
    }
  }


  vector<int> top(n);
  vector<int> bottom(n);
  vector<int> left(m);
  vector<int> right(m);
  for (int i = 0; i < n; i++) {
    cin >> top[i];
  }
  
  for (int i = 0; i < m; i++) {
    cin >>  left[i]; 
  }
  
  for (int i = 0; i < m; i++) {
   cin >> right[i]; 
  }
  for (int i = 0; i < n; i++) {
    cin >> bottom[i]; 
  }
  vector<vector<char>> ans(m,vector<char>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
        ans[i][j] = 'e';
    }
  }
  bool t=solution(arr,top,left,right,bottom,ans,0,0);

  if(t==false){
    cout << "No Solution" << endl;
  }

}