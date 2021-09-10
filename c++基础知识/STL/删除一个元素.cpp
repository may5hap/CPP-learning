#include<iostream>
#include<vector>
#include<list>

using namespace std;

int main(){
    vector<int> v;
    for(int i = 0; i<10; i++){
        v.push_back(i);
        cout << "v.capacity():" << v.capacity() << endl;
        // 两倍扩容
        cout << "v.size():" << v.size() << endl;
    }
    auto it = v.erase(v.begin());
    // auto it = v.erase(v.end()); // 这个会报段错误，
    cout << *it << endl;
    cout << "v.capacity():" << v.capacity() << endl;
    cout << "v.size():" << v.size() << endl;
    return 0;
}