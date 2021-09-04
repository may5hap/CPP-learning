#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n,x,y;
    vector<int> scores;
    cin >> n >> x >> y;
    int tmp;
    while(cin>>tmp){
        scores.push_back(tmp);
        if(cin.get()=='\n') break;
    }
    if(2*x>n || n>2*y) {
        cout << -1 << endl;
    }
    else cout << scores[n-y-1] << endl;
    return 0;
}