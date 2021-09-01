/**测试1，输入如下：
 * 1 2 3 4 5
 * 1,2,3,4,5
 * 1/2/3/4/5
*/

#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> nums;
    int tmp;
    while(cin>>tmp){
        nums.push_back(tmp);
        if(cin.get()=='\n') break;
    }
    for(int i = 0; i<nums.size(); i++){
        cout << nums[i] << " ";
    }
    cout <<endl;
    return 0;
}