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
    int kthSmallest(TreeNode* root, int k) {
        counter = k;
        inorder(root);
        return res;
    }

private:
    int res;
    int counter;
    
    void inorder(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left);
        counter--;
        if (counter == 0) {
            res = node->val;
            return;
        }
        inorder(node->right);
    }
};
