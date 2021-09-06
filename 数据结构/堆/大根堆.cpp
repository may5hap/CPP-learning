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
        // 栈顶元素满足：prio最大，或者prio并列最大且id最小
    }
    // < 重载，a < b，a是对象，< 是运算符， b是参数
    // 即后入堆的对象a跟堆中的元素满足关系：prio<a.prio || (prio==a.prio && id>a.id)
};

// 2、仿函数
class Comp{
public:
    bool operator()(const node& a, const node& b){
        return a.prio<b.prio || (a.prio==b.prio && a.id>b.id);
        // 栈顶元素满足：prio最大，或者prio并列最大且id最小
        // 这实际上是定义了一个排序规则，a表示前一个对象，b表示后一个对象，他们满足上面的关系
        // 
    }
};

int main(){
    priority_queue<node> pq1;
    priority_queue<node,vector<node>,Comp> pq2;
    cout << "有多少个节点：" << endl;
    int n;
    cin >> n;
    for(int i = 0; i<n; i++){
        cout << "请输入第" << i+1 << "个节点的id和prio：" << endl;
        int id, prio;
        cin >> id >> prio;
        node * cur = new node(id, prio);
        pq1.push(*cur);
        pq2.push(*cur);
        continue;
    }
    while(!pq1.empty()){
        node top = pq1.top();
        pq1.pop();
        cout << top.id << " " << top.prio << endl;
    }
    while(!pq2.empty()){
        node top = pq2.top();
        pq2.pop();
        cout << top.id << " " << top.prio << endl;
    }

    return 0;
}