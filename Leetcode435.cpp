//
// Created by Admin on 2021/11/15.
//
#include<vector>
#include <algorithm>
#include <iostream>

using namespace std;

int camp435(vector<int> i1, vector<int> i2){
    if (i1[0] == i2[0]) return i1[1] < i2[1];
    else return i1[0] < i2[0];
}

/**
 * 非常greedy的想法
 * https://leetcode.com/problems/non-overlapping-intervals/discuss/1283600/C%2B%2B-or-Explained-or-Greedy-and-DP-or
 * There can be only 3 cases in a prev interval and the next interval
    a. no overlap: we update the prev and nothing is removed
    b. total overlap: we choose the smaller one since it can accomodate more intervals now. We update prev and since we do not consider the other interval now, we update removedCount. 前面的完全覆盖后面的，当然移除前面的
    c. partial overlap: we choose the prev over current and update the removeCount. //部分覆盖，当出现部分覆盖，当然移除end points更大的，因为这会影响后面更多的interval

  https://leetcode.com/problems/non-overlapping-intervals/discuss/1466539/Explanation-for-all-such-%22Intervals%22-Problems
 * @param intervals
 * @return
 * prev就是代表上一个interval，挺有dp压缩后的内味
 *
 */
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if(intervals.size() <= 1)
        return 0;

    sort(intervals.begin(), intervals.end());

    int n= intervals.size(), prev=0, removeCount=0;

    for(int i=1;i<intervals.size(); i++){
        if(intervals[prev][1] > intervals[i][0]){ // overlapping
            if(intervals[prev][1] > intervals[i][1]){ // total overlap, move ahead & removeCount++
                prev = i;
            }
            removeCount++;    // partial overlap, only removeCount++; (no need to move ahead)
        }
        else { // no overlap, just move ahead, no change remove count
            prev = i;
        }
    }
    return removeCount;
}

/**
 * similiar to 2009,不管具体要怎么移除，只记录合理的窗口范围，dp[i]表示以ith的interval结尾的合理窗口，找到这样最大的窗口，然后用size-它，就是需要移除的最小count
 * 可惜超时了，但明显看到好几个方法也是这样过了，但那时多年前
 * @param intervals
 * @return
 */
int eraseOverlapIntervals2(vector<vector<int>>& intervals) {
    int ans = 0;
    sort(intervals.begin(), intervals.end(), camp435);


    for (int i = 0; i < intervals.size()-1; ++i) {
        if (intervals[i][0] == intervals[i+1][0] || intervals[i][1] == intervals[i+1][1]){
            ans++;
            int firstDiff = intervals[i][1] - intervals[i][0];
            int secondDiff = intervals[i+1][1] - intervals[i+1][0];
            if (firstDiff >= secondDiff){
                intervals.erase(intervals.begin() + i);
                i--;
            }else intervals.erase(intervals.begin() + i + 1);
        }
    }

    vector<int> dp(intervals.size());
    vector<bool> isInclude(intervals.size());

    for (int i = 0; i < intervals.size(); ++i) {
        dp[i] = 1;
    }

    for (int i = 1; i < intervals.size(); ++i) {
        for (int j = i-1; j >= 0; --j) {
            if (intervals[i][0] >= intervals[j][1]){
                dp[i] = max(dp[i],dp[j] + 1);
            }
        }

    }

    return ans+(intervals.size() - dp[intervals.size()-1]);
}

int main435(){
    vector<vector<int>> intervals;
    intervals.push_back({1,100});
    intervals.push_back({11,22});
    intervals.push_back({1,11});
    intervals.push_back({2,12});

    cout << eraseOverlapIntervals(intervals);
    return 0;
}
