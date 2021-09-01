/**测试2，二维数组的输入
 * 样例：
 * 1 2 3 4
 * 5 6 7 8
 * 9 10 11 12
*/

#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<vector<int> > nums;
    int tmp;
    int m;  //行数
    vector<int> arr;
    cout << "你的矩阵有多少行？" <<endl;
    cin >> m;
    int k = 1;      //k表示当前正在输入的是第多少行
    while(k<=m && cin>>tmp){
        arr.push_back(tmp);
        if(cin.get()=='\n'){
            nums.push_back(arr);
            k++;
            arr.clear();
        }
    }
    for(int i = 0; i<nums.size(); i++){
        for(int j = 0; j<nums[0].size(); j++){
            cout << nums[i][j]<<  " " ; 
        }
        cout <<endl;
    }
    return 0;
}