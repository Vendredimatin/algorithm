//
// Created by 刘汉乙 on 2021/5/19.
//
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    /*
    首先小%大，一定等于0，所以问题在于，所有大的数，都必须是小的数的倍数，或者可以理解为，大的数，必须是所有小的数的公倍数
    最朴素的：回溯，先排序，然后依次把大的加进来，检查大的是否是所有小的倍数，获得当前数的最小公倍数，直接用新的数/这个最小公倍数，好像直接验证最大的%次大的就行，因为最大%次大=0，因为次大%其他=0，所以最大%其他必为0.很自然地超时了
    dp:vector<vector<int>> dp(或者map),代表以key开头的符合条件的list，当到循环到该key时，直接赋值
    */

};

vector<int> ans368;
unordered_map<int, vector<int>> dp368;


void helper368(vector<int> nums, int k, vector<int> cur){
    for(int i = k; i < nums.size(); i++){
        int back = cur.back();
        if(nums[i]%back == 0){
            if(dp368.find(nums[i]) != dp368.end()){
                vector<int> tmp;
                tmp.insert(tmp.end(), cur.begin(),cur.end());
                tmp.insert(tmp.end(),dp368[nums[i]].begin(),dp368[nums[i]].end());
                if(cur.size() > ans368.size()) ans368 = cur;
            }else{
                cur.push_back(nums[i]);
                if(cur.size() > ans368.size()) ans368 = cur;
                helper368(nums, i+1, cur);
                cur.pop_back();
            }

        }
    }

    //在每次递归的最后，检查dp368
    for(int i = 0; i < cur.size(); i++){
        int num = cur[i];
        if(dp368.find(num) == dp368.end() || dp368[num].size() < (cur.size() - i + 1)){
            vector<int> result;
            result.insert(result.end(), cur.begin() + i, cur.end());
            dp368[num] = result;
        }
    }
}
vector<int> largestDivisibleSubset(vector<int>& nums) {
    if(nums.size() == 0) return ans368;
    sort(nums.begin(),nums.end());
    ans368.push_back(nums[0]);
    for(int i = 0; i < nums.size(); i++){
        vector<int> cur;
        cur.push_back(nums[i]);
        helper368(nums, i+1, cur);
    }

    return ans368;
}


#include <iostream>
using namespace std;

// 函数声明
double getAverage(int arr[], int size){
    int    i, sum = 0;
    double avg;

    for (i = 0; i < size; ++i)
    {
        sum += arr[i];
    }

    avg = double(sum) / size;

    arr[0]= 5;

    return avg;
}

int main368 ()
{
    // 带有 5 个元素的整型数组
    int balance[5] = {1000, 2, 3, 17, 50};
    double avg;

    // 传递一个指向数组的指针作为参数
    avg = getAverage( balance, 5 ) ;

    // 输出返回值
    cout << "平均值是：" << avg << endl;
    cout << balance[0];
    return 0;
}

