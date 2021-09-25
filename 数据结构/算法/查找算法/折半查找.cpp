#include<iostream>
#include<vector>
using namespace std;

int find(vector<int> & data, int n, int target){
    int left = 0, right = n-1;
    while(left<right){
        int mid = left + (right - left) >> 1;
        if(data[mid] == target) return mid;
        else if(data[mid] > target) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

int main(){
    // int n, target;
    // vector<int> data;
    // cout << "你的数组大小为：" << endl;
    // cin >> n;
    // cout << "请输入你的数组:" << endl;
    // int tmp;
    // while(cin >> tmp){
    //     data.push_back(tmp);
    //     if(cin.get()=='\n') break;
    // }
    // cout << "请输入你要查找的数：" << endl;
    // getchar();
    // cin >> target;
    // cout << target;
    int n = 5, target = 4;
    vector<int> data;
    for(int i = 1; i<=n; i++){
        data.push_back(i);
    }
    int ans = find(data, n, target);
    cout << "你要查找的数在下标为：" << ans << endl;
    return 0;
}