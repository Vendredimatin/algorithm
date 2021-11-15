//
// Created by Admin on 2021/11/15.
//
#include<vector>
#include<unordered_set>
#include <algorithm>

using namespace std;
//https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/discuss/1476157/Sort-and-Sliding-Window-oror-C%2B%2B-oror-O(NlogN)-and-O(N)
//https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/discuss/1471265/Java-Sort-%2B-sliding-window
//之前的想法是，先将小窗口合规化，如果小窗口不合规，那么右指针增加时的大窗口也不会合规，所以想法是合规每一个窗口，但左指针却不会动，加入两个指针都不会动的话，那么一定不是个标准的滑动窗口，比较naive
//同时这个想法会涉及到具体的数，需要考虑到将不合规的数num1变成合规的数num2，这格局就比较小了，就会陷入如何改动成合规的数，还要考虑如何不会重复，变得越来越复杂
//正确的想法应该是考虑合规的窗口，找到最大的合规的窗口，那么n-其size，就是最小操作次数，根本不需要考虑具体的数
int minOperations(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    sort(nums.begin(),nums.end());
    
    vector<int> arr;
    arr.push_back(nums[0]);
    for (int i = 1; i < n; ++i) {
        if (nums[i] == nums[i-1]) continue;
        arr.push_back(nums[i]);
    }

    for (int i = 0, j = 0; j < arr.size(); ++j) {
        while(i <= j && arr[j] - arr[i] > n-1) i++;
        ans = max(ans, j - i + 1);
    }
    
    
    return n - ans;
}

int main2009(){
    vector<int> nums({8,5,9,9,8,4});;
    minOperations(nums);
    return 0;
}