#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,s,r;
    cin >> n>>m;
    vector<vector<int>> arr(n,vector<int> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    cin >> s >> r;
    
    //ring rotate
    
    //fill 1D
    int rmin=s-1,rmax=n-s,cmin=s-1,cmax=m-s,count=0,total=2*((rmax-rmin)+(cmax-cmin));
    int a[total];
    for(int i=rmin,j=cmin;j<=cmax && count<total;j++){
        a[count]=arr[i][j];
        count++;
    }
    rmin++;
    for(int i=rmin,j=cmax;i<=rmax && count<total;i++){
        a[count]=arr[i][j];
        count++;
    }
    cmax--;
    for(int i=rmax,j=cmax;j>=cmin && count<total;j--){
        a[count]=arr[i][j];
        count++;
    }
    rmax--;
    for(int i=rmax,j=cmin;i>=rmin && count<total;i--){
        a[count]=arr[i][j];
        count++;
    }
    
    
    //rotate the array
    r=r%total;
    if(r<0){
        r=r+total;
    }
    rotate(a, a + (r % total), a + total);
    
    //fill 2D
    rmin=s-1,rmax=n-s,cmin=s-1,cmax=m-s,count=0,total=2*((rmax-rmin)+(cmax-cmin));
    for(int i=rmin,j=cmin;j<=cmax && count<total;j++){
        arr[i][j]=a[count];
        count++;
    }
    rmin++;
    for(int i=rmin,j=cmax;i<=rmax && count<total;i++){
        arr[i][j]=a[count];
        count++;
    }
    cmax--;
    for(int i=rmax,j=cmax;j>=cmin && count<total;j--){
        arr[i][j]=a[count];
        count++;
    }
    rmax--;
    for(int i=rmax,j=cmin;i>=rmin && count<total;i--){
        arr[i][j]=a[count];
        count++;
    }
    
    
    
    //display array
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
}