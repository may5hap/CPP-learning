/**
 * @file Dijkstra.cpp
 * @author whao
 * @brief 
 * @version 0.1
 * @date 2021-09-20
 * 
 * @copyright Copyright (c) 2021
 * 
 * dijkstra 算法是经典的最短路算法，它适用于有向图，且路径权值非负，它只能求单源最短路径
 */

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Dijkstra{
public:
    class Node{
    public:
        int id;     // 节点编号
        int len;    // 从源节点到当前节点的距离
        Node(int _id, int _len):id(_id),len(_len){}
        bool operator()(Node a, Node b){
            return a.len <= b.len;
        }
    };

    vector<vector<int> > g;
    int src;
    void initGraph(){
        int n;
        cout << "你有多少个节点：" << endl;
        cin >> n;
        g = vector<vector<int> >(n,vector<int>(n,INT_MAX));
        cout << "你有多少条边：" << endl;
        int m;
        cin >> m;
        cout << "请输入边的起点和终点以及权值：" << endl;
        int s,d,w;
        int k = 0;
        while(k<m && cin >> s>> d>> w){
            g[s][d] = w;
            k++;
        }
    }

    bool setSrc(int n){
        if(n > g.size()) return false;
        else {
            src = n;
            return true;
        }
    }

    void dijkstra(){
        priority_queue<Node*> q;
        vector<bool> visited(g.size(),false);// 是否已经确定
        // vector<int> dis(g.size(),INT_MAX);  // 从源节点到个节点的距离
        q.push(new Node(src,0));
        // dis[src] = 0;
        while(!q.empty()){
            Node * node = q.top();
            visited[node->id] = true;
            for(int i = 0; i<g[node->id].size(); i++){
                if(g[node->id][i] < INT_MAX && !visited[i]){
                    Node * newNode = new Node(i, node->len + g[node->id][i]);
                    if(node->len + g[node->id][i] < )
                }
            }
        }
    }
};

int main(){
    Dijkstra d;
    d.initGraph();
    d.dijkstra();
    return 0;
}