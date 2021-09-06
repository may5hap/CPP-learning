/**题目大意：
 * 3个窗口：1，2，3
 * 顾客排队，顾客有优先级，优先级大的先服务，优先级一样的按id排队
 * 也是填空题，就测试一下优先级队列
*/

// 哇，太菜了，这个都写错了

#include<iostream>
#include<vector>
#include<queue>

using namespace std;


// 大顶堆实现方式1:仿函数（重载运算符（））
struct node
{
    int id, type;

};


struct comp{
    bool operator()(const node & a, const node & b){
        if(a.type != b.type) return a.type < b.type;
        else return a.id > b.id; 
    }
};

int main(){
    priority_queue<node,vector<node>,comp> pq1;
    for(int i = 0; i<5; i++){
        int id, type;
        cin >> id >> type;
        node * cur = new node();
        cur->id = id;
        cur->type = type;
        pq1.push(*cur);
    }
    while(!pq1.empty()){
        node cur = pq1.top();
        pq1.pop();
        cout << cur.id << "   " << cur.type << endl;
    }
    return 0;
}