//#include<vector>
// we have defined the necessary header files here FOR this problem.
// IF additional header files are needed IN your program, please IMPORT here.
#include <iostream>

//using namespace std;
int main()
{
    int m,n;
    int matrix[110][110];
    // vector<vector<int> > matrix;
    char ch;
    int tmp;
    std::cin >> m >> ch >> n;
    // vector<int> v;
    int cnt = 0;
    while(std::cin>>tmp){
        matrix[cnt/n][cnt%n] = tmp;
        cnt++;
        if(std::cin.get()=='\n')break;
    }
    int dp[110][110] = {INT32_MAX};
    //vector<vector<int> > dp(m,vector<int>(n,INT32_MAX));
    dp[m-1][n-1] = 0;
    for(int i = m-2; i>0; i--){
        if(matrix[i][n-1]!=0) dp[i][n-1] = dp[i+1][n-1]+1;
    }
    for(int j = n-2; j>0; j--){
        if(matrix[m-1][j]!=0) dp[m-1][j] = dp[m-1][j+1]+1;
    }
    for(int i = m-2; i>0; i--){
        for(int j = n-2; j>0; j--){
            if(matrix[i][j]!=0) dp[i][j] = std::min(dp[i+1][j],dp[i][j+1])+1;
        }
    }
    std::cout << dp[1][1] << std::endl;
    return 0;
}
