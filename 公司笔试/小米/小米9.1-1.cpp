/** 题目描述：
 * 这个题我刷到过
 * 有序数组A和数组B，A的空间可存储A、B所有的值，将B合并到A并排序
 * 这个题不难，问题是输入很恶心，如下（需要处理逗号）：
 * m=2,n=3
 * 1,3
 * 2,4
 * 要求输出：
 * 1 2 3 4
 * 
 * 排序算法：逆向双指针
 * 
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    void merge(vector<int>& A, vector<int>& B, int m, int n){
        A.reserve(m+n);
        int p1 = m - 1, p2 = n - 1;
        int tail = m + n - 1;
        int cur;
        while (p1 >= 0 || p2 >= 0) {
            if(p1<0) A[tail--] = B[p2--];
            else if(p2<0) A[tail--] = A[p1--];
            else if(A[p1]>B[p2]) A[tail--] = A[p1--];
            else A[tail--] = B[p2--];
        }
    }
};

int main(){
    int m, n;
    char ch;
    cin >> ch >> ch >> m >> ch >> ch >> ch >> n;
    vector<int> A;
    vector<int> B;
    int tmp;
    while(cin >> tmp){
        A.push_back(tmp);
        if(cin.get()=='\n') break;
    }
    while(cin >> tmp){
        B.push_back(tmp);
        if(cin.get()=='\n') break;
    }
    //测试是否输入成功
    for(int i = 0; i<m; i++){
        cout << A[i] << " ";
    }
    cout <<endl;
    for(int j =0; j<n; j++){
        cout << B[j]<< " ";
    }
    cout <<endl;
    Solution s;
    s.merge(A,B,m,n);
    for(int i = 0; i<m+n; i++){
        cout << A[i] << " ";
    }
    cout <<endl;
    return 0;
}