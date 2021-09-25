#include<iostream>
#include<vector>
#include<string>
using namespace std;


int func(long long & s){
    int ans = -1;
    long long tmp = s;
    int ans1 = 0, ans2 = 1;
    while(tmp > 0){
        ans1 += (tmp&1);
        tmp = tmp >> 1;
    }
    tmp = s;
    // 找到比s大的2的值数次幂的数
    long long a = 1;
    while(a<tmp){
        a*=2;
    }

    int b = a - tmp;
    while(b>0){
        ans2 += (b&1);
        b = b >> 1;
    }
    ans = min(ans1,ans2);
    return ans;
}

int main(){
    long long s;
    cin >> s;
    int ans = func(s);
    cout << ans << endl;
    return 0;
}