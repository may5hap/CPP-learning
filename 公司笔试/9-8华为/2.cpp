#include <vector>
#include<iostream>
using namespace std;
// we have defined the necessary header files here FOR this problem.
// IF additional header files are needed IN your program, please IMPORT here.
int main()
{
    int m,n;
    vector<vector<int> > matrix;
    char ch;
    int tmp;
    cin >> m >> ch >> n;
    vector<int> v;
    while(cin>>tmp){
        v.push_back(tmp);
        if(v.size()==m){
            matrix.push_back(v);
            v.clear();
            if(cin.get()=='\n') break;
        }
    }
    vector<vector<int> > dp(m,vector<int>(n,INT32_MAX));
    dp[m-1][n-1] = 0;
    for(int i = m-2; i>0; i--){
        if(matrix[i][n-1]!=0) dp[i][n-1] = dp[i+1][n-1]+1;
    }
    for(int j = n-2; j>0; j--){
        if(matrix[m-1][j]!=0) dp[m-1][j] = dp[m-1][j+1]+1;
    }
    for(int i = m-2; i>0; i--){
        for(int j = n-2; j>0; j--){
            if(matrix[i][j]!=0) dp[i][j] = min(dp[i+1][j],dp[i][j+1])+1;
        }
    }
    cout << dp[1][1] << endl;
    return 0;
}
