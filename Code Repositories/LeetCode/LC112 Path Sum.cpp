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
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root)
            return false;
        if(!root->left && !root->right)
            return sum == root->val;
        bool ltag = hasPathSum(root->left, sum - root->val);
        bool rtag = hasPathSum(root->right, sum - root->val);
        return ltag || rtag;
    }
};