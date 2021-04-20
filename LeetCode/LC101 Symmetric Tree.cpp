/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool judge(TreeNode* lrt, TreeNode* rrt)
    {
        if (lrt == NULL && rrt == NULL)
            return true;
        else if (lrt == NULL || rrt == NULL)
            return false;
        else if (lrt->val != rrt->val) 
            return false;
        return judge(lrt->left, rrt->right) && judge(lrt->right, rrt->left);
    }
    bool isSymmetric(TreeNode* root) 
    {
        return judge(root,root);
    }
};