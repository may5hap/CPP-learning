#include<iostream>
#include<vector>
#include<string>
using namespace std;

int selectTable(string& personpertable, int& m, char& gender){
    int ret = -1;
    if(gender=='M'){
        for(int i = 0; i<m; i++){
            if(personpertable[i]=='1') {
                ret = i;
                break;
            }
            else if(ret==-1 && personpertable[i]=='0'){
                ret = i;
            }
            else continue;
        }
        personpertable[ret]+=1;
        return ret;
    }
    else{
        for(int i = 0; i<m; i++){
            if(personpertable[i]=='0'){
                ret = i;
                break;
            }
            else if(ret==-1 && personpertable[i]=='1') ret = i;
            else continue;
        }
        personpertable[ret] += 1;
        return ret;
    }
}

int main(){
    int t,m,n;
    cin >> t;
    for(int i = 0; i<t; i++){
        cin >> m;
        //vector<int> personpertable(m);
        string personpertable;
        cin >> personpertable;
        //for(int k = 0; k<m; k++) personpertable[k]=person[k]-'0';
        cin >> n;
        string gender;
        cin >> gender;
        for(int j = 0; j<n; j++){
            cout << selectTable(personpertable,m,gender[j])+1 << endl;
        }
    }
    return 0;
}