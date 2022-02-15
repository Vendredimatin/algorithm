//
// Created by 刘汉乙 on 2022/1/24.
//
#include<vector>
#include<string>
#include<queue>
#include<regex>
#include<sstream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * 当作完全二叉树来解还是不行，产生多余的遍历
 * @param root
 * @return
 */
string serialize1(TreeNode* root) {
    if (root == NULL) return "";

    queue<TreeNode*> q;
    vector<string> v;
    q.push(root);
    string ans = "";
    ans += to_string(root->val);
    int size = 1;

    while (!q.empty()){
        int sz = q.size();
        bool isAllNull = true;
        while (sz-- > 0){
            TreeNode* node = q.front(); q.pop();
            if (node != NULL){
                if (node->left != NULL || node->right != NULL) isAllNull = false;
                if (node-> left != NULL){
                    ans = ans +  "," + to_string(node->left->val);
                }else ans = ans +  "," + "null";

                if (node-> right != NULL){
                    ans = ans +  "," + to_string(node->right->val);
                }else ans = ans +  "," + "null";

                q.push(node->left);
                q.push(node->right);
                size += 2;
            }else{
                ans = ans +  "," + "null";
                ans = ans +  "," + "null";

                q.push(NULL);
                q.push(NULL);
                size += 2;
            }
        }

        if (isAllNull) break;

    }

    return ans;
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    if (data.empty()) return NULL;

    vector<string> vals;
    string collect = "";
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == ',') {
            vals.push_back(collect);
            collect = "";
        }
        else collect += data[i];
    }
    vals.push_back(collect);

    queue<TreeNode*> q;
    TreeNode* head = new TreeNode(stoi(vals[0]));
    q.push(head);

    int i = 0;
    while (q.size() != 0) {
        TreeNode* p = q.front(); q.pop();
        int left = i * 2 + 1;
        if (left < vals.size()) {
            if ( vals[left] != "null") {
                TreeNode *leftNode = new TreeNode(stoi(vals[left]));
                p->left = leftNode;
                q.push(leftNode);
            }else q.push(NULL);

        }
        int right = left + 1;
        if (right < vals.size()) {
            if ( vals[right] != "null") {
                TreeNode *rightNode = new TreeNode(stoi(vals[right]));
                p->right = rightNode;
                q.push(rightNode);
            }else q.push(NULL);
        }
        i++;
    }

    return head;
}

/**
 * 有点把这道题想复杂了，题目已经说是binary search tree，所以可以根据大小来判别左右关系
 * 包括层序遍历也是
 * 原来的做法超时应该是多次遍历了
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        return encode(root);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string item;
        TreeNode* root = NULL;

        while (getline (ss, item, '-'))
            root = insert(root, stoi(item));

        return root;
    }

private:
    string encode(TreeNode* root) {
        if (!root)
            return "";
        return to_string(root->val) + "-" + encode(root->left)+encode(root->right);
    }

    TreeNode* insert(TreeNode* root, int val) {
        if (root == NULL) {
            TreeNode* temp=new TreeNode(val);
            return temp;
        }

        if (val<=root->val)
            root->left=insert(root->left,val);

        else
            root->right=insert(root->right,val);

        return root;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);
    root->right->left->left = new TreeNode(6);
    root->right->left->right = new TreeNode(7);
    string data = serialize1(root);
    deserialize(data);
    return 0;
}
