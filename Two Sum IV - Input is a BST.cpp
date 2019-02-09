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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return dfs(root, k, s);
    }
    bool dfs(TreeNode* root, int k, unordered_set<int>& s) {
        if (root == nullptr) return false;
        if (s.count(k - root->val) > 0) {
            return true;
        }
        s.insert(root->val);
        return dfs(root->left, k, s) || dfs(root->right, k, s);
    }
};
