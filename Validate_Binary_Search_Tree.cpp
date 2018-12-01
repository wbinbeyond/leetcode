/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if (root == nullptr) return true;
        return helper(root, LONG_MAX, LONG_MIN);
    }

private: 
    bool helper(TreeNode* root, long long max, long long min) {
        if (root == nullptr) return true;
        if (root->val >= max || root->val <= min) return false;
        bool left = helper(root->left, root->val, min);
        bool right = helper(root->right, max, root->val);
        return left && right;
    }
};
