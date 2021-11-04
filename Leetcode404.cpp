//
// Created by 刘汉乙 on 2021/11/4.
//
struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

int turnLeft(TreeNode* root);


int sumOfLeftLeaves(TreeNode* root) {
    if(root == nullptr) return 0;
    int ans = 0;
    ans += turnLeft(root->left);
    ans += sumOfLeftLeaves(root->right);

    return ans;
}


int turnLeft(TreeNode* root){
    if(root == nullptr) return 0;
    if(root->left == nullptr && root->right == nullptr)   return root->val;
    if(root->left == nullptr && root->right != nullptr) return sumOfLeftLeaves(root->right);
    return turnLeft(root->left);
}
