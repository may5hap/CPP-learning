#include<iostream>
#include<vector>

using namespace std;

int func(int n){
    int ans = 0;
    int tmp = n;
    while(tmp!=0){
        int yushu = tmp % 10;
        if(yushu == 0){}
        else if(n % yushu == 0){
            ans++;
        }
        tmp = tmp / 10;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;
    cout << func(n) << endl;
    return 0;
}