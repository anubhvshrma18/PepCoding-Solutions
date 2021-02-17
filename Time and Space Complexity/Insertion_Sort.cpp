#include <bits/stdc++.h>
using namespace std;

bool isGreater(vector<int> &arr, int i, int j) {
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

void insertionSort(vector<int> &v){
    int n=v.size();
    for(int j=1;j<n;j++){
        for(int i=j;i>=1;i--){
            if(isGreater(v,i,i-1)){
                swap(v,i-1,i);
            }
            else{
                break;
            }
        }
    }
}
int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i=0;i<n;i++){
		cin >> v[i];
	}

	insertionSort(v);
	for(auto x:v){
	    cout << x << endl;
	}
	return 0;
}