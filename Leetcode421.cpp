//
// Created by Admin on 2021/11/12.
//

#include<iostream>
#include<vector>
using namespace std;
/**
 * 首先，使用了trie
 * 如果直接遍历的话，需要使用O(n2)遍历才能够得到结果，这是一题经典的空间换时间，将O(n2)分解成两次O(n)
 * 使用了trie，就将不同数字对应的0、1统一到一起，这样每个数字和这棵树比的时候，就是在跟所有数字都比
 * 有个贪心的想法，如果对于第ith位的digit，如果digit是1，那么就往0的方向走，因为是从左边往右边遍历，优先追求左边的digit的异或成1，这样数字才会更大
 * https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/discuss/91052/C%2B%2B-Trie-69ms-beats-85
 * https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/discuss/166211/Python-O(n)-solution-for-dummies-like-me-easy-commented-solution-with-explanation
 */
struct TrieNode{
    TrieNode* next[2];
    TrieNode(){next[0] = NULL; next[1] = NULL;}
};

int findMaximumXOR(vector<int>& nums) {
    TrieNode* root = new TrieNode();

    for(int num : nums){
        TrieNode* cur = root;
        for (int i = 31; i >= 0; --i) {
            int digit = (num >> i) & 1;
            if (cur->next[digit] == NULL){
                cur->next[digit] = new TrieNode();
            }
            cur = cur->next[digit];
        }
    }

    int ans = 0;
    for(int num : nums){
        TrieNode* cur = root;
        int tmp = 0;
        for (int i = 31; i >= 0; --i) {
            int digit = (num >> i) & 1;
            if (cur->next[digit ^ 1]){  //如果在该digit不能异或为1，那么就从原来的路走
                tmp += 1 << i;
                cur = cur->next[digit ^ 1];
            }else cur = cur->next[digit];
        }

        ans = max(tmp, ans);
    }

    return  ans;
}

int main421(){
    vector<int> nums({3,10,5,25,2,8});
    cout << findMaximumXOR(nums);
    return 0;
}
