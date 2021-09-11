/**
 * @file 2两数之和.cpp
 * @author whao (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-09-07
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**题目：
 * 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 * 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 如： 
 * 2  ->  4  ->  3
 * 5  ->  6  ->  4
 * 结果为：
 * 7  ->  0  ->  8
 */

/**分析：
 * 只要按照链表的顺序依次相加即可，如果有进位就在下一个节点+1
 * 难点：
 * 1、数学：每个位置上的数字是第一位的进位+两个位置的数字
 * 2、链表长度不一样怎么处理（怎么高效处理）
 * 3、怎么处理临界情况和条件
 */

#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode():val(0),next(nullptr){}
    ListNode(int _val):val(_val),next(nullptr){}
    ListNode(int _val,ListNode* _next):val(_val),next(_next){}
};

class Solution{
public:
    ListNode* addSum(ListNode* head1, ListNode* head2){
        int carry = 0;
        ListNode* head = nullptr;       // 记录结果的头
        ListNode* tail = nullptr;       // 记录结果的尾
        while(carry || head1 || head2){
            int n1 = (head1 == nullptr)? 0 : head1->val;
            int n2 = (head2 == nullptr)? 0 : head2->val;
            int sum = n1 + n2 + carry;
            if(head == nullptr){
                head = tail = new ListNode(sum % 10);
            }
            else {
                tail->next = new ListNode(sum % 10);
                tail = tail->next;
            }
            if(head1 != nullptr) head1 = head1->next;
            if(head2 != nullptr) head2 = head2->next;
            carry = sum / 10;
        }
        return head;
    }
};

int main(){
    cout << "请输入你的两个链表："  << endl;
    ListNode* l1 = new ListNode();
    ListNode* l2 = new ListNode();
    ListNode* ll1 = l1;
    ListNode* ll2 = l2;
    int tmp;
    while(cin>>tmp){
        l1->next = new ListNode(tmp);
        l1 = l1->next;
        if(cin.get()=='\n') break;
    }
    while(cin>>tmp){
        l2->next = new ListNode(tmp);
        l2 = l2->next;
        if(cin.get()=='\n') break;
    }
    Solution s;
    ListNode* ans = s.addSum(ll1->next,ll2->next);
    while(ans != nullptr){
        cout << ans->val << " ";
        ans = ans->next;
    }
    cout << endl;
    return 0;
}