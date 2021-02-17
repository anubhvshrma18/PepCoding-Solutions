#include <bits/stdc++.h>
using namespace std;

bool isSmaller(vector<int> &arr, int i, int j) {
    cout << "Comparing " << arr[i] << " and " << arr[j] << endl;
    if (arr[i] < arr[j]) {
      return true;
    } else {
      return false;
    }
}
void swap(vector<int> &arr, int i, int j) {
    cout << "Swapping " << arr[i] << " and " << arr[j] << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    
}

void selectionSort(vector<int> &v){
    for(int i=0;i<v.size()-1;i++){
        int min=v[i];
        int idx=i;
        for(int j=i+1;j<v.size();j++){
            if(isSmaller(v,j,idx)){
                min=v[j];
                idx=j;
            }
        }
        swap(v,i,idx);
    }
}
int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}

	selectionSort(v);
	for(auto x:v){
	    cout << x << endl;
	}
	return 0;
}