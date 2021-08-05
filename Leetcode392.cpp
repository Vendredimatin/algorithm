//
// Created by 刘汉乙 on 2021/8/4.
//
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * 一看到这个标签有dp的标签，就想到了应该是这种dp，将其中一个字符串作为横坐标，另外一个字符串作为纵坐标
 * @param s
 * @param t
 * @return
 */
bool isSubsequence(string s, string t) {
    /*int l = 0;
    for (int r = 0; r < t.size(); ++r) {
        if (s[l] == t[r]){
            l++;
        }
    }

    return l == s.size();*/

    //dp
    int m = s.size(), n = t.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1));
    for (int i = 0; i <= m; ++i)    dp[i][0] = 0;
    for (int j = 0; j <= n; ++j)    dp[0][j] = 0;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s[i-1] == t[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }

    return dp[m][n] == m;
}

int main392(){
    cout << isSubsequence("axc","ahbgdc");
    return 0;
}