/*--

*	*	*	*	*	
*	*	*	*	
*	*	*	
*	*	
*
--
*/	

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    for (int row = n; row >= 1; row--) {
        for (int i = 1; i <= row; i++) {
            cout << "*\t";
        }
        cout << "\n";
    }
    
    return 0;

}