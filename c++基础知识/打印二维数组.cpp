#include<iostream>
using namespace std;

void Print(int * arr, int m, int n){
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            cout << arr[i*m+j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arr[3][2] = {1,2,3,4,5,6};
    Print(arr,3,2);
    return 0;
}