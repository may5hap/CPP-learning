// 约瑟夫环
/**
 * 0,1,···,n-1这n个数字排成一个圆圈，从数字0开始，
 * 每次从这个圆圈里删除第m个数字（删除后从下一个数字开始计数）。求出这个圆圈里剩下的最后一个数字。
 * 例如，0、1、2、3、4这5个数字组成一个圆圈，从数字0开始每次删除第3个数字，
 * 则删除的前4个数字依次是2、0、4、1，因此最后剩下的数字是3。
*/

/**分析：
 * 这个题呈现明显的数学性质，虽然可能第一眼看不出来什么规律，但是跟数学挂钩的就应该多往动态规划上面靠
 * 动态规划的核心主要是状态的设计和递推关系的确定
 * 现在我们知道的是n个数组成的一个环形数组，每个m删掉一个元素
 * 第一个应该删掉的元素是 第 m%n 个元素，删除此元素之后，数组变成了一个 长度为 n-1 的环形数组
 * 此时环形数组的起点是原来数组中的 第 （m+1）%n 个元素，比如：
 * 0 1 2 3 4 首先删除掉 2， 剩下： 0 1 3 4， 且下一次应该从3开始，即： 3 4 0 1
 * 如果一直 3 4 0 1 最后剩下的结果为 x（x表示第x个元素）， 那么0 1 2 3 4 最后剩下的结果应该是多少？
 * 答：第 （x+m%n）%n 个元素
 * 其实删掉一个元素前后 最后剩下的都是同一个元素，为了方便表示新的数组从第（m+1）%n 个元素开始，
 * 所以原数组和新数组的元素坐标的对应关系就是答案，即原数组元素坐标： y= （x+m%n）%n
 * 到最后只剩一个元素的数组中，剩下的元素坐标就是0
 * 为方便写成动态规划的形式，定义状态：dp[m][n] 表示数组长度为n,每隔m删除一个元素，最后剩下的那个元素坐标
 * 递推关系： dp[m][n] = (dp[m][n-1]+m%n)%n
 * dp[m][1] = 0;
 * m是固定的，定义一维的dp即可
 * dp[n]表示数组长度为n，最后剩下的元素坐标，dp[n] = (dp[n-1]+m%n)%n
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int lastRemainint(int n, int m){
        vector<int> dp(n+1);
        dp[1] = 0;
        for(int i =2; i<=n; i++){
            dp[i] = (dp[i-1] + m%i) % i;
        }
        return dp[n];
    }
};

int main(){
    int n, m;
    cout << "数组长度：" << endl;
    cin >> n;
    cout << "每隔多少删除一个元素？" <<endl;
    cin >>m;
    Solution s;
    cout << "最后剩下的元素是：" << s.lastRemainint(n,m) <<endl;
    return 0;
}