//
// Created by 刘汉乙 on 2021/11/17.
//

//
// Created by 刘汉乙 on 2021/11/13.
//
#include<vector>
#include <iostream>

using namespace std;

int longestOnes(vector<int>& nums, int k) {
    int oneCount = 0, start = 0, end = 0, ans = 0;
    int n = nums.size();
    for (; end < n; end++) {
        if (nums[end] == 1) oneCount++;
        while(end - start + 1 - oneCount > k){
            if (nums[start] == 1) oneCount--;
            start++;
        }

        ans = max(ans, end-start+1);
    }

    return ans;
}

int maxConsecutiveAnswers(string answerKey, int k) {
    int maxCount = 0, start = 0, end = 0, ans = 0;
    int tf[26] = {0};
    int n = answerKey.size();
    for (; end < n; end++) {
        tf[answerKey[end] - 'A']++;
        maxCount = max(maxCount, tf[answerKey[end] - 'A']);
        while(end - start + 1 - maxCount > k){
            tf[answerKey[start] - 'A']--;
            start++;
        }

        ans = max(ans, end-start+1);
    }

    return ans;
}

int main1004(){
    //vector<int> nums({0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1});
    int k = 1;
    string answerKey = "TTFTTFTT";
    //cout << longestOnes(nums,k);
    cout << maxConsecutiveAnswers(answerKey, k);
    return 0;
}
