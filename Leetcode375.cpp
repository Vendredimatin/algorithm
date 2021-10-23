//
// Created by 刘汉乙 on 2021/8/1.
//
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

vector<vector<int>> dp375;

/**
 * 终于get到了自顶向下的dp精髓了，一开始没想出来是因为把dp限于一维dp，所以动态方程不能合理确定，遍历方式也无法合理确定。当拓展到二维dp后，动态方程和遍历方式就合理多了
 * dp[i][j]表示i～j这个范围内需要的money， dp[i][j] = x + max(helper(i,x-1), helper(x+1,j))
 * 从这个动态方程可以看到，解决i～j的动态方程时，是假定x不是猜中的number，那么只能要么往后，要么往前遍历，只有把两个子过程完成之后，才能对完整的过程进行动态转移。
 * 所以dp375的遍历思考角度应该是自顶向下和自底向上，而不是想着对index：i向前还是向后
 * @param l
 * @param r
 * @return
 */

//自顶向上
int helper375(int l, int r){
    if (l >= r) return 0;
    if (dp375[l][r] != 0) return dp375[l][r];

    int ans = INT_MAX;
    for (int i = l; i <= r; ++i) {
        int temp = i + max(helper375(l, i-1), helper375(i+1, r));
        ans = min(ans, temp);
    }

    dp375[l][r] = ans;
    return dp375[l][r];
}

/**
 * 体会自底向上的流程，自底向上一定是要求之前的dp先被处理掉，所以要求如果是i～j，那么i要慢慢远离j，而不是让i从0开始，慢慢靠近j
 * @param n
 * @return
 */
int getMoneyAmount(int n) {
    dp375.resize(n+1, vector<int>(n+1));
    /*helper375(1,n);
    return dp375[1][n];*/
    //自底向上
    for (int j = 2; j <= n; ++j) {
        for (int i = j-1; i > 0; i--) {
            int ans = INT_MAX;
            for (int k = i+1; k < j; ++k) {
                int temp = k + max(dp375[i][k-1], dp375[k+1][j]);
                ans = min(ans, temp);
            }

            dp375[i][j] = (i == j - 1)?i:ans;
        }
    }
    return dp375[1][n];
}

int main375(){
    int n = 10;
    cout << getMoneyAmount(n);
    return 0;
}
