#include<iostream>
#include<string>

using namespace std;

int main(){
    string s;
    /**cin >>
     * @brief cin属于istream流，需要包括头文件iostream 
     * cin 以 空格、换行、制表符作为结束标志，cin发生在输入之后
     * 对结尾的换行符不做操作，也就是换行符还在缓冲区
     */
    cin >> s;
    cout << s << endl;


    /**cin.getline()
     * @brief 用来输入整行字符串
     * 有两种重载版本，第一个：包含两个参数，第一个参数为字符数组，第二个参数为读入字符的最大个数(注意这个个数应该大于等于1，因为'\0'占一位)
     * 第二个：包含三个参数，第一个参数和第二个参数与上一个一样，多了一个结束符，默认为'\0'
     */
    char s1[100];
    getchar();              // getline()发生在输入之前，如果缓冲区有数据，则读取，所以这里要先清空缓冲区
    // cin.getline(s1, 100);
    // cout << s1 << endl;

    cin.getline(s1, 3);     // 读取包括'\0'在内的3个字符
    cout << s1 << endl;
    

    // cin.getline(s1, 100, 'g');
    // cout << s1 << endl;

    /**getline()
     * @brief getline()属于string流，需要包含头文件string
     * 以整行输入，并自动去掉最后的回车符
     */

    while((getchar()!='\n'));
    // s = "\n";
    getline(cin,s);
    cout << s << endl;
    return 0;
}