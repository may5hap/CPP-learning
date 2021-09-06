/**两种方式实现大根堆（note：c++默认大根堆，但是对于自定义类型还是需要重新定义）
 * 1、重载运算符<
 * 2、仿函数（重载运算符()）
*/

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// 1、重载运算符<
class node{
public:
    int id;
    int prio;
    node(int _id, int _prio):id(_id),prio(_prio){}
    bool operator<(const node & a) const {
        return prio<a.prio || (prio==a.prio && id>a.id);
    }
};

int main(){
    priority_queue<node> pq1;
    cout << "有多少个节点：" << endl;
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        cout << "请输入第" << i+1 << "个节点的id和prio：" << endl;
        int id, prio;
        cin >> id >> prio;
        node * cur = new node(id, prio);
        pq1.push(*cur);
        continue;
    }
    while(!pq1.empty()){
        node top = pq1.top();
        cout << top.id << " " << top.prio << endl;
    }

    return 0;
}