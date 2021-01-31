/*
*	*	*	*	*	
	*	*	*	*	
		*	*	*	
			*	*	
				*
*/
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for (int row = 1; row <= n; row++) {
        for (int i = 1; i <= row - 1; i++) {
            cout <<"\t";
        }
        for (int j = 1; j <= n - row + 1; j++) {
            cout <<"*\t";
        }
        cout << "\n";
    }
    return 0;

}