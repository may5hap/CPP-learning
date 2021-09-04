#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> data(n);
    for(int i = 0; i<n; i++){
        cin >> data[i];
    }
    for(int i = 0; i<n; i++){
        cout << data[i] << "  ";
    }
    cout << endl;
    return 0;
}