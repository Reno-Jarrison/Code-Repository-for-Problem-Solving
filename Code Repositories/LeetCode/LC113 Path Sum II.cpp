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
    vector<vector<int>> ans;
    vector<int> buf;
    void dfs(TreeNode* root, int sum)
    {
        if (root == nullptr)
            return;
        buf.push_back(root->val);
        sum -= root->val;
        if (!root->left && !root->right && sum == 0)
            ans.push_back(buf);   
        dfs(root->left, sum);
        dfs(root->right, sum);
        buf.pop_back();
        sum += root->val;
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        dfs(root, sum);
        return ans;
    }
};