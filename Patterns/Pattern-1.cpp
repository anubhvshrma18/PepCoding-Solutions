/*--

*	
*	*	
*	*	*	
*	*	*	*	
*	*	*	*	*	

---*/
//Code
#include <iostream>
using namespace std;

int main(int argc, char **argv){
    int n;
    cin >> n;
    for (int row = 1; row <= n; row++) {
        for (int str = 1; str <= row; str++) {
                cout <<"*\t";
            }
            cout << endl;
    }
    return 0;
   //write your code here
   
}