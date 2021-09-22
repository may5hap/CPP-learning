#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main(){
    int t,n,k;
    unordered_map<int,int> in;
    vector<int> out;
    cin >> t;
    for(int i = 0; i<t; i++){
        cin >> n >> k;
        int tmp;
        int m = 0;
        while(m < n && cin >> tmp){
            in[tmp] = m;
            m++;
            if(cin.get()=='\n') break;
        }
        m = 0;
        while(m < n && cin >> tmp){
            out.push_back(tmp);
            m++;
            if(cin.get()=='\n') break;
        }
        // for(auto x:in) cout << x << " ";
        // cout << endl;
        // for(auto x: out) cout << x << " ";
        // cout << endl;
        int ans = 0;
        for(int j = 0; j<n; j++){
            if(in[out[j]]-j>=k) ans += 1;
        }
        cout << ans << endl;
    }
    return 0;
}