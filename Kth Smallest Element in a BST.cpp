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


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root, k);
    }

private:
    int inorder(TreeNode* node, int& counter) { //counter needs to be a reference of int
        if (node == nullptr) return -1;
        int lr = inorder(node->left, counter);
        counter--;  // minus 1 first before checking counter
        if (counter == 0) return node->val;
        int rr = inorder(node->right, counter);
        return lr != -1 ? lr : rr;
    }
};


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        int counter = 0;
        TreeNode* p = root;
        while (p != nullptr || !s.empty())
        {
            if (p != nullptr) {
                s.push(p);
                p = p->left;
            }
            else {
                p = s.top(); s.pop();
                counter++;
                if (counter == k) return p->val;
                p = p->right;
            }
        }
        return -1;
    }
};
