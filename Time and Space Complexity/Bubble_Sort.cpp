#include<bits/stdc++.h>
using namespace std;

void swap(vector<int> &arr, int i, int j) {
    cout << "Swapping " << arr[i] << " and " << arr[j] << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

bool isSmaller(vector<int> &arr, int i, int j) {
    cout << "Comparing " << arr[i] << " and " << arr[j] << endl;
    if (arr[i] < arr[j]) {
      return true;
    } else {
      return false;
    }
}

void bubbleSort(vector<int> &v){
    int n=v.size();
    int i=n-1;
    while(i>=0){
        for(int j=0;j<i;j++){
            if(isSmaller(v,j+1,j)){
                swap(v,j+1,j);
            }
        }
        i--;
    }
}
int main(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    
    bubbleSort(v);
    // /
    for(auto x:v){
        cout << x << endl;
    }
}