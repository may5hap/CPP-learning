/**
 * @file 111树的最小高度.cpp
 * @author whao
 * @brief 
 * @version 0.1
 * @date 2021-09-12
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * @brief 
 * 给定一个二叉树，找出其最小深度。
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 说明：叶子节点是指没有子节点的节点。
 */

/**BFS
 * @brief 
 * 核心数据结构：队列queue，题很简单，懒得写了
 */

#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue<int> q;
    q.push(1);
    cout << q.front() << endl;
    q.pop();
    cout << q.size() << endl;
    return 0;
}