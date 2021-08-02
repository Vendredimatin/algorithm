//
// Created by 刘汉乙 on 2021/6/18.
//
#include<iostream>
#include<vector>
using namespace std;

vector<int> preSums;
int ansA = INT_MAX;

void dfs(vector<int> nums, int start, int segments, vector<int> tmp, int m){
    int n = nums.size();
    if (start >= n && segments != m)    return;
    if (segments == m){
        int curMax = 0;
        for (int num : tmp) {
            curMax = max(curMax, num);
        }
        int other = preSums[n-1] - preSums[start] + nums[start];
        curMax = max(other, curMax);
        ansA = min(curMax, ansA);
        return;
    }

    for (int i = start; i < n; ++i) {
        int tmpSum = preSums[i] - preSums[start] + nums[start];
        tmp.push_back(tmpSum);
        dfs(nums, i+1, segments+1, tmp, m);
        tmp.pop_back();
    }

}

int splitArray(vector<int>& nums, int m) {
    int n = nums.size();
    preSums.resize(n);

    for (int i = 0; i < n; ++i) {
        preSums[i] = nums[i];
        if (i > 0){
            preSums[i] += preSums[i-1];
        }
    }

    vector<int> tmp;
    dfs(nums, 0, 1, tmp,m);

    return ansA;
}




int mainAs(){
    vector<int> nums({1,4,4});
    int n = nums.size();
    int m = 3;
    ansA = splitArray(nums, m);
    cout << ansA;
    return 0;
}
