#include <iostream>
#include <vector>

using namespace std;

void input(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
}

void print(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << endl;
    }
    cout << endl;
}

// used for swapping ith and jth elements of array
void swap(vector<int> &arr, int i, int j)
{
    cout << ("Swapping index " + to_string(i) + " and index " + to_string(j)) << endl;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void sort012(vector<int> &arr)
{   
    int i=0,j=0,k=arr.size()-1;
    for(;j<=k;){
        if(arr[j]==0){
            swap(arr,j,i);
            i++;
            j++;
        }
        else if(arr[j]==1){
            j++;
        }
        else{
            swap(arr,j,k);
            k--;
        }
        
    }
}

int main()
{
    int n, m;
    cin >> n;
    vector<int> A(n, 0);
    input(A);

    sort012(A);
    print(A);
    return 0;
}