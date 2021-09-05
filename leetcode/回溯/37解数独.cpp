#include<iostream>
#include<vector>

using namespace std;


class Solution1 {
public:
    vector<vector<char> > ans;
    vector<vector<char> > solveSudoku(vector<vector<char> >& board) {
        int n = board.size();
        dfs(board,n,0,0);
        return ans;
    }
    void dfs(vector<vector<char> >& board, int n, int r, int c){
        if(r==n){
            ans = board;
            return;
        }
        if(c==n) {
            dfs(board,n,r+1,0);
            return;
        }
        if(board[r][c]!='.') {
            dfs(board,n,r,c+1);
            return;
        }
        for(char i = '1'; i<='9'; i++){
            if(valid(board,n,i,r,c)){
                board[r][c]=i;
                dfs(board,n,r,c+1);
                board[r][c]='.';
            }
        }
    }
    bool valid(vector<vector<char> >& board, int n, char ch, int r, int c){
        int rth = r/3, cth = c/3;
        for(int i = 0; i<n; i++){
            if(board[i][c]==ch) return false;
            if(board[r][i]==ch) return false;
        }
        for(int i = rth*3; i<rth*3+3; i++){
            for(int j = cth*3; j<cth*3+3; j++){
                if(board[i][j]==ch) return false;
            }
        }
        return true;
    }
};


// 上面的代码报段错误，不知道哪里有问题
// 找到问题了，上面代码可用
// 下面可以：

/**分析：
 * 由于只需要找到一个就可以，所以当找到一个的时候就终止，每次从头开始遍历数组，如果遇到空的位置，则去试探可以放什么数
 * 当所有的数字试探完之后，说明当前的棋盘不能继续，即前面的数字摆放有些问题，则返回false，导致回溯
 * 如果遍历完整个棋盘都没有返回，说明找到合适的棋盘，则返回true，此时的board即为解
*/
class Solution {
private:
bool backtracking(vector<vector<char> >& board) {
    for (int i = 0; i < board.size(); i++) {        // 遍历行
        for (int j = 0; j < board[0].size(); j++) { // 遍历列
            if (board[i][j] != '.') continue;
            for (char k = '1'; k <= '9'; k++) {     // (i, j) 这个位置放k是否合适
                if (isValid(i, j, k, board)) {
                    board[i][j] = k;                // 放置k
                    if (backtracking(board)) return true; // 如果找到合适一组立刻返回
                    board[i][j] = '.';              // 回溯，撤销k
                }
            }
            return false;                           // 9个数都试完了，都不行，那么就返回false
        }
    }
    return true; // 遍历完没有返回false，说明找到了合适棋盘位置了
}
bool isValid(int row, int col, char val, vector<vector<char> >& board) {
    for (int i = 0; i < 9; i++) { // 判断行里是否重复
        if (board[row][i] == val) {
            return false;
        }
    }
    for (int j = 0; j < 9; j++) { // 判断列里是否重复
        if (board[j][col] == val) {
            return false;
        }
    }
    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;
    for (int i = startRow; i < startRow + 3; i++) { // 判断9方格里是否重复
        for (int j = startCol; j < startCol + 3; j++) {
            if (board[i][j] == val ) {
                return false;
            }
        }
    }
    return true;
}
public:
    void solveSudoku(vector<vector<char> >& board) {
        backtracking(board);
    }
};


int main(){
    vector<vector<char> > boardinit(9,vector<char>(9,'.'));
    char inp[9][9] = {  {'5','3','.','.','7','.','.','.','.'},
                        {'6','.','.','1','9','5','.','.','.'},
                        {'.','9','8','.','.','.','.','6','.'},
                        {'8','.','.','.','6','.','.','.','3'},
                        {'4','.','.','8','.','3','.','.','1'},
                        {'7','.','.','.','2','.','.','.','6'},
                        {'.','6','.','.','.','.','2','8','.'},
                        {'.','.','.','4','1','9','.','.','5'},
                        {'.','.','.','.','8','.','.','7','9'}};
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            boardinit[i][j]=inp[i][j];
        }
    }
    // Solution1 s1;
    // boardinit = s1.solveSudoku(boardinit);
    Solution s;
    s.solveSudoku(boardinit);
    for(int i = 0; i<9; i++){
        for(int j = 0; j<9; j++){
            cout << boardinit[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}