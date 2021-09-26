#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int solve(vector<int> & arr, int n){
    int ret = INT_MIN;
    for(int i = 0; i<n; i++){
        int idx = i;
        int tmpans = 0;
        while(idx<n && idx >= 0){
            tmpans += arr[idx];
            idx += arr[idx];
        }
        ret = max(ret,tmpans);
    }
    cout << ret << endl;
    return ret;
}

int main(){
    int t;
    int k = 0;
    vector<int> outans;
    cin >> t;
    int n;
    while(k<t && cin >> n){
        vector<int> arr;
        cout << n << endl;
        int tmp;
        while(cin>>tmp){
            arr.push_back(tmp);
            if(cin.get()=='\n') break;
        }
        int ans = solve(arr,n);
        outans.push_back(ans);
        // if(k==t) break;
        k++;
    }
    for(int x:outans) cout << x << endl;
    return 0;
}