#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

int main(){
    string s;
    cin >> s;
    stack<int> nums;
    int n = s.size();
    char preop = '+';
    int num = 0;
    for(int i = 0; i<n; i++){
        char ch = s[i];
        if(isdigit(ch)){
            num = num * 10 + ch - '0';
        }
        if(i == n - 1 || !isdigit(ch)){
            if(preop == '@'){
                int prenum = nums.top();
                nums.pop();
                int tmp = prenum | (prenum + num);
                nums.push(tmp);
            }
            else if(preop == 'x' && ch != '@'){
                int prenum = nums.top();
                nums.pop();
                int tmp = prenum * num;
                nums.push(tmp);
            }
            else{
                nums.push(num);
            }
            preop = ch;
            num = 0;
        }
    }
    int ans = 0;
    while(!nums.empty()){
        ans += nums.top();
        nums.pop();
    }
    cout << ans << endl;
    return 0;
}