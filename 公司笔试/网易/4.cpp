#include<iostream>
#include<vector>
#include<cassert>
using namespace std;

int n, a, b;
vector<vector<char> > maze;

int main(){
    cin >> n >> a >> b;
    // getchar();
    for(int i = 0; i<n; i++){
        char ch;
        while(scanf("%c",&ch)){
            if(ch=='\0') break;
            maze[i].push_back(ch);
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            cout << maze[i][j];
        }
        cout << endl;
    }
    return 0;
}