//
// Created by Admin on 2021/11/17.
//

//
// Created by Admin on 2021/11/17.
//
#include<vector>
#include <iostream>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int ans437 = 0;

/**
 * 或者可以用一个map记录到每一个节点的前缀和，然后targetSum - curSum是否存在，用two sum的思想来求解，来找想要求的和是否存在
 * @param root
 * @param targetSum
 * @param sums
 */
void helper(TreeNode* root, int targetSum, vector<int> sums){
    if (root == NULL) return;

    sums.push_back(sums.back() + root->val);

    for (int i = sums.size()-1; i >= 0; --i) {
        if (sums.back() - sums[i] == targetSum) ans437++;
    }

    if (sums.back() == targetSum)   ans437++;

    helper(root->left, targetSum, sums);
    helper(root->right, targetSum, sums);
}

int pathSum(TreeNode* root, int targetSum) {
    vector<int> sums;
    sums.push_back(root->val);
    helper(root->left, targetSum, sums);
    helper(root->right, targetSum, sums);
    return ans437;
}

int main437(){
    TreeNode* node1 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(-2);
    TreeNode* node3 = new TreeNode(1);
    TreeNode* node4 = new TreeNode(11);
    TreeNode* node5 = new TreeNode(3, node1, node2);
    TreeNode* node6 = new TreeNode(2, NULL, node3);
    TreeNode* node7 = new TreeNode(5, node5, node6);
    TreeNode* node8 = new TreeNode(-3, NULL, node4);
    TreeNode* root = new TreeNode(10, node7, node8);
    cout << pathSum(root, 8);
    return 0;

}