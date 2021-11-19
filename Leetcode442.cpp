//
// Created by Admin on 2021/11/19.
//
#include<vector>
#include<math.h>
using namespace std;
/**
 * Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.
 * 本道题的思路来源于题目中限制了nums在只有size为n的情况下，只会出现1~n这几个数字，那么很合理地就想到把数字安放在对应的位置，这样当进行交换时，总会出现重复放置，从而找到重复的元素
 * @param nums
 * @return
 */
vector<int> findDuplicates(vector<int>& nums) {
    vector<int> ans;
    for (int i = 0; i < nums.size(); ++i) {
        while(nums[i] - 1 != i && nums[i] != -1){
            int temp = nums[nums[i]-1];
            nums[nums[i]-1] = nums[i];
            if (temp == nums[i]){
                ans.push_back(temp);
                nums[i] = -1;
            }else
                nums[i] = temp;
        }
    }

    return ans;
}

/**
 * 一个不需要交换的办法，用负数做识别，是否visit过
 * https://leetcode.com/problems/find-all-duplicates-in-an-array/discuss/775798/c%2B%2B-Four-Solution-or-O-(N*N)-to-greater-O(N)-or-Explain-All
 * @param nums
 * @return
 */
vector<int> findDuplicates2(vector<int>& nums) {
    if(nums.empty())return {};
    vector<int>ans;
    for(int i=0;i<nums.size();i++){
        if(nums[abs(nums[i])-1]<0)
            ans.push_back(abs(nums[i]));
        nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
    }
    return ans;
}

/**
 * leetcode 448 和442是镜像问题
 * @param nums
 * @return
 */
vector<int> findDisappearedNumbers(vector<int>& nums) {
    if (nums.empty()) return {};
    vector<int> ans;
    for (int i = 0; i < nums.size(); ++i) {
        int index = abs(nums[i]) - 1;
        if (nums[index] >= 0)
            nums[index] = -nums[index];
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] >= 0) ans.push_back(i+1);
    }

    return ans;
}


int main(){
    vector<int> nums({4,3,2,7,8,2,3,1});
    findDisappearedNumbers(nums);
    return 0;
}