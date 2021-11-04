//
// Created by 刘汉乙 on 2021/8/5.
//
#include <vector>
#include<math.h>
using namespace std;

/**
 * 虽然滚动数组的方法失效了，但这的确是一个比较好的思路，使得可以很自然地求出每一个F（k），滚动数组真nb
 * 但是方法却要求O（n），O（n）的方法偏数学一点，要求对动态方程进行递归找规律，其实递推的确也是动态方程的本质之一
 * https://leetcode.com/problems/rotate-function/discuss/1243652/DP-Code-Explained-in-Detail-or-O-(N)-time-or-O-(N)-space
 * @param nums
 * @return
 */

int maxRotateFunction(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n,vector<int>(2*n));

    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; ++j) {
            if (i == 0){
                dp[i][j] = i * nums[j];
            }else{
                dp[i][j+i] = i * nums[(j + i)%n] + dp[i-1][j+i-1];
            }
        }
    }

    int ans = INT_MIN;
    for (int i = n-1; i < 2*n-1; ++i) {
        ans = max(ans, dp[n-1][i]);
    }

    return ans;
}

int maxRotateFunction2(vector<int>& A) {
    if (A.size() == 0) return 0;

    long long allsum = 0;
    long long sum2 = 0;
    for (int i = 0; i < A.size(); i++) {
        allsum += A[i] * i;
        sum2 += A[i];
    }

    long long result = allsum;
    for (int i = 0; i < A.size(); i++) {
        allsum -= sum2;
        allsum += A[i];
        allsum += A[i] * int(A.size() - 1);
        result = max(allsum, result);
    }

    return result;
}

int main396(){
    vector<int> v({4,3,2,6});
    maxRotateFunction(v);
    return 0;
}